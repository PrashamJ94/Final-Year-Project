import argparse
import json
import os
import re

import numpy as np
from create_tests import JavaTestsConstruction
from run_tests import RunJavaTests
from llm_preprocessor import LLMPreprocessor
import time
from collections import defaultdict
import matplotlib.pyplot as plt

class Pipeline:
    def __init__(self,testfiles,mode,run_number):
        self.testfiles = testfiles
        self.test_cases_generated = [] # List of files which needed test case generation
        self.compiler_errors = [] # List of files which had compilation errors
        self.comp_errors_post_preprocessing = [] # List of files which had compilation errors after preprocessing
        self.runtime_errors = [] # List of files which had runtime errors
        self.testfile_data = defaultdict(dict)
        self.gi_experiments = {}
        self.results_folder_name = 'results__' + time.strftime("%Y%m%d-%H%M%S")
        self.mode = mode
        self.run_number = run_number
    
    
    def check_test_cases(self, testfile):
        # Check if the test file has test cases
        test_file_name = testfile.split('.')[0] + 'Test.java'
        with open('./tmp/com/example/' + test_file_name, 'r') as f:
            for line in f:
                if 'Token size exceeded' in line:
                    self.test_cases_generated.append(testfile)
                    return True
        
        return False

    def copy_files(self, file):
        # Copy the files to a tmp directory
        if not os.path.exists('./tmp'):
            os.system('mkdir tmp')
        
        if not os.path.exists('./tmp/com/'):
            os.system('mkdir tmp/com')
        
        if not os.path.exists('./tmp/com/example'):
            os.system('mkdir tmp/com/example')
        
        test_file_name = file.split('.')[0] + 'Test.java'
        os.system(f'cp ../LLM-Translations/GPT-4/evalplus/Python/Java/{file} ./tmp/com/example/{file}')
        os.system(f'cp ../LLM-Translations/GPT-4/evalplus/Python/Java/{test_file_name} ./tmp/com/example/{test_file_name}')
        os.system(f'cp ./junit-4.10.jar ./tmp/')
        os.system(f'cp ./junit-platform-console-standalone-1.7.2-all.jar ./tmp/')
    
    def delete_files(self):
        if not os.path.exists('./processed_dataset'):
            os.system('mkdir processed_dataset')
        
        if not os.path.exists(f'./processed_dataset/{self.mode}/run_{self.run_number}'):
            os.system(f'mkdir ./processed_dataset/{self.mode}/run_{self.run_number}')
        
        os.system(f'cp ./tmp/com/example/*.java ./processed_dataset/{self.mode}/run_{self.run_number}/')
        os.system('rm -rf ./tmp/com/example/*')
    
    def delete_directories(self):
        os.system('rm -rf ./tmp')
    
    def save_filewise_results(self):
        
        os.system(f'mkdir experiment_results/{self.mode}/{self.results_folder_name}')
        with open('experiment_results/' + self.mode + '/' + self.results_folder_name + '/results.txt', 'w') as f:
            
            f.write('\nFiles which had compilation errors:\n')
            for file in self.compiler_errors:
                f.write(file + '\n')
            
            f.write('\nFiles which had compilation errors after preprocessing:\n')
            for file in self.comp_errors_post_preprocessing:
                f.write(file + '\n')
            
            f.write('\nFiles which had runtime errors:\n')
            for file in self.runtime_errors:
                f.write(file + '\n')
            
        
        self.gi_experiments['Compilation Errors'] = self.comp_errors_post_preprocessing
        self.gi_experiments['Runtime Errors'] = self.runtime_errors
        
        with open('experiment_results/' + self.mode + '/' + self.results_folder_name + '/gi_experiments.json', 'w') as f:
            json.dump(self.gi_experiments, f, indent=4)
        
        # dump the testfile_data dictionary to a json file
        with open('experiment_results/' + self.mode + '/' + self.results_folder_name + '/filewise_results.json', 'w') as f:
            json.dump(self.testfile_data, f, indent=4)
    
    def compute_statistics(self):
        total_test_cases = len(self.testfiles)
        
        total_error_files = list(set(self.compiler_errors + self.comp_errors_post_preprocessing + self.runtime_errors))
        total_error_files = len(total_error_files)
        
        files_without_errors = total_test_cases - total_error_files
        
        comp_files_fixed_by_preprocessing = len(self.compiler_errors) - len(self.comp_errors_post_preprocessing)
        
        # compilation error files which have runtime errors
        comp_files_with_runtime_errors = []
        for file in self.runtime_errors:
            if file in self.compiler_errors:
                comp_files_with_runtime_errors.append(file)
        
        comp_files_with_runtime_errors = len(comp_files_with_runtime_errors)
        comp_files_without_runtime_errors = len(self.compiler_errors) - comp_files_with_runtime_errors
        stats = [
        f'Total test cases: {total_test_cases}',
        f'Total files with errors: {total_error_files}',
        f'Total files without errors: {files_without_errors}',
        f'Total files with compile time errors: {len(self.compiler_errors)}',
        f'Total files compiled after preprocessing: {comp_files_fixed_by_preprocessing}',
        f'Total files with compile time errors post preprocessing: {len(self.comp_errors_post_preprocessing)}',
        f'Total files with runtime errors: {len(self.runtime_errors)}',
        f'Total files with runtime errors after preprocessing: {comp_files_with_runtime_errors}'
    ]
    
        # Print to console
        for stat in stats:
            print(stat)
    
        # Write to file
        with open(f'experiment_results/{self.mode}/{self.results_folder_name}/statistics.txt', 'w') as f:
            for stat in stats:
                f.write(stat + '\n')
        
        
    def save_results(self):
        self.save_filewise_results()
        self.compute_statistics()
        self.generate_plots()
    
    def generate_plots(self):
        # 4-6 plots minimum 
        # create a box plot of the time taken for compilation, test generation, and test run
        with open('experiment_results/' + self.mode + '/' + self.results_folder_name + '/filewise_results.json', 'r') as f:
            data = json.load(f)
        
        os.system('mkdir experiment_results/' + self.mode + '/' + self.results_folder_name + '/plots')
        compilation_times = []
        test_generation_times = []
        test_run_times = []
        
        for file,obj in data.items():
                if file == 'HumanEval_39.java':
                    continue
                compilation_times.append(obj['Compilation Time'])
                test_generation_times.append(obj['Test Generation Time'])
                test_run_times.append(obj['Test Run Time'])
        
        # Create a box plot of the time taken for compilation, test generation, and test run
        plt.figure(figsize=(10, 6))
        plt.boxplot(
            [[t * 1000 for t in compilation_times], 
            [t * 1000 for t in test_generation_times], 
            [t * 1000 for t in test_run_times]], 
            labels=['Compilation Time', 'Test Generation Time', 'Test Run Time'])
        plt.title('Box Plot of Time Taken (in milliseconds)')
        plt.ylabel('Time (milliseconds)')
        plt.grid(axis='both')
        plt.savefig('experiment_results/' + self.mode + '/' + self.results_folder_name + '/plots/box_plot.png')
        plt.close()
        
        # Create a plot of the number of normal files,files with compilation errors, files with runtime errors
        total_test_cases = len(self.testfiles)
        
        files_with_only_runtime_errors = []
        for file in self.runtime_errors:
            if file not in self.compiler_errors:
                files_with_only_runtime_errors.append(file)
        
        total_error_files = list(set(self.compiler_errors + files_with_only_runtime_errors))
        files_with_only_runtime_errors = len(files_with_only_runtime_errors)
    
        total_error_files = len(total_error_files)
        
        files_without_errors = total_test_cases - total_error_files
        
        # Now compute after preprocessing
        files_with_only_runtime_errors_after_preprocessing = []
        for file in self.runtime_errors:
            if file in self.compiler_errors:
                files_with_only_runtime_errors_after_preprocessing.append(file)
            
        files_with_only_runtime_errors_after_preprocessing = files_with_only_runtime_errors + len(files_with_only_runtime_errors_after_preprocessing)
        
        normal_files = []
        for file in self.testfiles:
            if file not in self.comp_errors_post_preprocessing and file not in self.runtime_errors:
                normal_files.append(file)
        normal_files = len(normal_files)
        
        
        print('Normal files before preprocessing:', files_without_errors)
        print('Files with compilation errors before preprocessing:', len(self.compiler_errors))
        print('Files with runtime errors before preprocessing:',files_with_only_runtime_errors)
        
        print('Normal files after preprocessing:', normal_files)
        print('Files with compilation errors after preprocessing:', len(self.comp_errors_post_preprocessing))
        print('Files with runtime errors after preprocessing:', len(self.runtime_errors))
        
       # Create a combined grouped bar chart
        plt.figure(figsize=(12, 10))

        # Set the width of bars and positions
        bar_width = 0.35
        index = np.arange(3)

        # Create the bars
        before_bars = plt.bar(index, 
                            [files_without_errors, len(self.compiler_errors), files_with_only_runtime_errors],
                            bar_width, 
                            color='#1f77b4', 
                            label='Before Preprocessing')

        after_bars = plt.bar(index + bar_width, 
                            [normal_files, len(self.comp_errors_post_preprocessing), len(self.runtime_errors)],
                            bar_width, 
                            color='#ff7f0e', 
                            label='After Preprocessing')

        # Add labels and title
        plt.xlabel('File Categories')
        plt.ylabel('Number of Files')
        plt.title('Error Distribution Before and After Preprocessing')
        plt.xticks(index + bar_width/2, ['Error Free Files', 'Files with Compilation Errors', 'Files with Runtime Errors'])
        plt.legend()

        # Add value labels on top of each bar
        def add_labels(bars):
            for bar in bars:
                height = bar.get_height()
                plt.text(bar.get_x() + bar.get_width()/2., height + 0.15,
                        f'{int(height)}', ha='center', va='bottom')

        add_labels(before_bars)
        add_labels(after_bars)

        plt.grid(axis='y', linestyle='--', alpha=0.5)
        plt.tight_layout()
        plt.savefig('experiment_results/' + self.mode + '/' + self.results_folder_name + '/plots/error_distribution_comparison.png')
        plt.close()
        
        

    def main(self):
        for file in self.testfiles:

            total_time_st = time.time()
            self.copy_files(file)
            test_file_name = file.split('.')[0] + 'Test.java'
            rt_instance = RunJavaTests(file,test_file_name,'./tmp/com/example/')
            
            # generate the test cases for the file and store them in a tmp directory
            
            st = time.time()
            if self.check_test_cases(file):
                print('Generating test cases for', file,'...')
                JavaTestsConstruction(file,test_file_name).generate_junit_tests('./tmp/com/example/')
            else:
                os.system(f'cp ../LLM-Translations/GPT-4/evalplus/Python/Java/{test_file_name} ./tmp/com/example/{test_file_name}')
                
            self.testfile_data[file]['Test Generation Time'] = time.time() - st
            
            compile_code,error_files,stdout,stderr = rt_instance.compile()
            if compile_code:
                print('Compilation errors in', ','.join(error_files), '...')
                
            if compile_code and len(error_files) == 1 and error_files[0] == test_file_name:
                os.system(f'cp ../LLM-Translations/GPT-4/evalplus/Python/Java/{test_file_name} ./tmp/com/example/{test_file_name}')
            
            st = time.time()
            compile_code,error_files,stdout,stderr = rt_instance.compile()
            self.testfile_data[file]['Compilation Time'] = time.time() - st
            self.testfile_data[file]['Preprocessed'] = False
            self.testfile_data[file]['Preprocessing Time'] = 0
            self.testfile_data[file]['Compilation Time After Preprocessing'] = 0
            
            self.testfile_data[file]['Compilation'] = {}
            self.testfile_data[file]['Compilation']['Stdout'] = stdout
            self.testfile_data[file]['Compilation']['Stderr'] = stderr
            self.testfile_data[file]['Compilation']['Error Files'] = error_files
            try:
                if compile_code:
                    # preprocess the file and store it back
                    print('Preprocessing', file,'...')
                    self.compiler_errors.append(file)
                    st = time.time()
                    LLMPreprocessor(error_files,'./tmp/com/example/').run()
                    preprocessing_time = time.time() - st
                    self.testfile_data[file]['Preprocessing Time'] = preprocessing_time
                    self.testfile_data[file]['Preprocessed'] = True
            except:
                self.testfile_data[file]['Result'] = 'Skipping'
                self.testfile_data[file]['Test Run Time'] = 0
                self.testfile_data[file]['Total Time'] = time.time() - total_time_st
                self.comp_errors_post_preprocessing.append(file)
                self.delete_files()
                self.testfile_data[file]['Result Time'] = {}
                
                self.testfile_data[file]['Result Time']['Stdout'] = stdout
                self.testfile_data[file]['Result Time']['Stderr'] = stderr
                continue
            
            compile_code, error_files,stderr,stdout= rt_instance.compile()
            
            
            if self.testfile_data[file]['Preprocessed']:
                st = time.time()
                compile_code, error_files,stderr,stdout= rt_instance.compile()
                self.testfile_data[file]['Compilation Time After Preprocessing'] = time.time() - st
            
            if compile_code:
                print('Compilation errors after preprocessing in', ','.join(error_files), '...')
                print(stdout)
                print(stderr)
                self.testfile_data[file]['Test Run Time'] = 0
                self.testfile_data[file]['Total Time'] = time.time() - total_time_st
                self.comp_errors_post_preprocessing.append(file)
                self.delete_files()
                self.testfile_data[file]['Result'] = 'Compilation Error after preprocessing'
                self.testfile_data[file]['Result Time'] = {}
                
                self.testfile_data[file]['Result Time']['Stdout'] = stdout
                self.testfile_data[file]['Result Time']['Stderr'] = stderr
                continue
            
            # run the tests and get the results
            print('Running tests for', file,'...')
            st = time.time()
            returncode, results,stdout,stderr = rt_instance.run_tests()
            if returncode != 0:
                # detect how many tests failed
                self.runtime_errors.append(file)
            
            self.testfile_data[file]['Test Run Time'] = time.time() - st
            print('Results for', file, ':', results)
            self.testfile_data[file]['Result'] = results
            self.testfile_data[file]['Result Time'] = {}
            self.testfile_data[file]['Result Time']['Stdout'] = stdout
            self.testfile_data[file]['Result Time']['Stderr'] = stderr
            self.testfile_data[file]['Total Time'] = time.time() - total_time_st
            self.delete_files()
        
        self.delete_directories()
        self.save_results()
        print('Pipeline completed.')
        print('Results saved to results.txt')

    
if __name__ == '__main__':                 
    parser = argparse.ArgumentParser(
        description="Final Year Project Experiment Pipeline",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    
    def parse_list(arg):
        return arg.split(',')

   
    parser.add_argument(
        "--mode",
        type=str,
        default = 'test',
        choices=['test', 'train'],
    )
    
    parser.add_argument(
        "--run_number",
        type=int,
        default = 0,
        help="Run number for the experiment",
    )
    
    parser.add_argument(
        "--files",
        type=str,
        default = 'test',
        choices=['test', 'train'],
    )
    
    args = parser.parse_args()
    
    testfiles = []
    if args.files == 'train':
         with open('./train_files.txt', 'r') as f:
            for line in f:
                testfiles.append(line.strip())
    else:
        with open('./test_files.txt', 'r') as f:
            for line in f:
                testfiles.append(line.strip())
        
        
    pipeline = Pipeline(testfiles,args.mode,args.run_number)
    pipeline.main()