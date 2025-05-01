import json
import os
import argparse
import time
from magpie_setup import MagpieSetup
import subprocess
from collections import defaultdict

class GIPipeline:
    def __init__(self, mutation_operators, algorithm, mode, file_set,run_number):
        self.mode = mode
        self.file_set = file_set
        self.run_number = run_number
        folder = sorted(os.listdir(f'./experiment_results/{self.file_set}'))[run_number - 1]
        with open(f'./experiment_results/{self.file_set}/{folder}/gi_experiments.json', 'r') as f:
            data = json.load(f)
        self.files = data['Runtime Errors']
        self.mutation_operators = mutation_operators
        self.algorithm = algorithm
        self.path = './processed_dataset/'+self.file_set+'/'+'run_'+str(run_number)+'/'
        self.experiment_results = defaultdict(dict)
    
    def detect_junit_version(self, test_file):
        with open(self.path + test_file, 'r') as f:
            for line in f:
                if 'org.junit.jupiter' in line:
                    return 'JUnit 5'
            
        return 'JUnit 4'

    def save_results(self):
        if not os.path.exists('./gi_experiments/'):
            os.makedirs('./gi_experiments/')
        if not os.path.exists('./gi_experiments/'+self.mode+'/'):
            os.makedirs('./gi_experiments/'+self.mode+'/')
        if not os.path.exists('./gi_experiments/'+self.mode + '/' + self.file_set+'/'):
            os.makedirs('./gi_experiments/'+self.mode + '/' + self.file_set+'/')
        
        output_path = './gi_experiments/'+self.mode + '/' + self.file_set+'/'
        
        results_folder = 'results__' + time.strftime("%Y%m%d-%H%M%S")
        os.makedirs(output_path + results_folder, exist_ok=True)
        with open(output_path + results_folder + '/results.json', 'w') as f:
            json.dump(self.experiment_results, f, indent=4)
        
        print(f"Results saved to {output_path + results_folder}/results.json")
        
    def main(self):
        magpie = MagpieSetup()
        
        for file in self.files:
            src_file = file
            test_file = src_file.replace('.java', 'Test.java')
            junit_version = self.detect_junit_version(test_file)
            magpie.setup(self.path,src_file, test_file, junit_version, self.mutation_operators, self.algorithm)
            
            # Run the experiment 
            cmd = "python3 magpie genetic_programming --scenario ./uncompilable/_magpie/scenario.txt"
            cmd = cmd.split()
            try:
                process = subprocess.run(
                    cmd, 
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,  # Return strings instead of bytes
                    timeout = 180
                )
            except subprocess.TimeoutExpired:
                pass
            
            stdout, stderr = process.stdout, process.stderr
            self.experiment_results[src_file]['stdout'] = stdout
            self.experiment_results[src_file]['stderr'] = stderr

        self.save_results()           
if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(
        description="Final Year Project GI Pipeline",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    
    def parse_list(arg):
        return arg.split(',')
    
    
    parser.add_argument(
        "--run_number",
        type=int,
        default = 1,
        help="Number of times to run the pipeline"
    )
    
    parser.add_argument(
        "--mode",
        type=str,
        default="standard",
        choices=["standard", "llm-crossover", "novel-mutation"],
        help="Mode of the pipeline"
    )
    
    parser.add_argument(
        "--set",
        type=str,
        default="test",
        choices=["train", "test"],
        help="Set of files to be processed"
    )
    args = parser.parse_args()
    if args.mode == "standard":
        mutation_operators = ["SrcmlStmtDeletion", "SrcmlStmtInsertion", "SrcmlStmtReplacement"]
        algorithm = "GeneticProgrammingUniformConcat"
    elif args.mode == "llm-crossover":
        mutation_operators = ["SrcmlStmtDeletion", "SrcmlStmtInsertion", "SrcmlStmtReplacement"]
        algorithm = "GeneticProgrammingLLM"
    elif args.mode == "novel-mutation":
        mutation_operators = ["SrcmlStmtDeletion", "SrcmlLLMTypeReplacement", "SrcmlStmtReplacement"]
        algorithm = "GeneticProgrammingUniformConcat"
    
    pipeline = GIPipeline(mutation_operators,algorithm, args.mode, args.set, args.run_number)
    pipeline.main()