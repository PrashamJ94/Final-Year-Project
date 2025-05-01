import os
import sys

# check if uncompilable directory exists
class MagpieSetup:
    def clean(self):
        if not os.path.exists('./uncompilable'):
            os.makedirs('./uncompilable')
            print("Directory created: ./uncompilable")

        # check if uncompilable/com/example directory exists

        if not os.path.exists('./uncompilable/com/'):
            os.makedirs('./uncompilable/com/')

        if not os.path.exists('./uncompilable/com/example'):
            os.makedirs('./uncompilable/com/example')
            
        else:
            # remove all files in the directory
            files = os.listdir('./uncompilable/com/example')
            for file in files:
                os.remove(f'./uncompilable/com/example/{file}')
                print(f"Removed {file}")
        
        if not os.path.exists('./uncompilable/_magpie'):
            os.makedirs('./uncompilable/_magpie')
            
        
    def copy_files(self,path,src_file,test_file):
        
        # copy the src_file to the uncompilable/com/example directory
        os.system(f"cp {path}/{src_file} ./uncompilable/com/example/")
        
        # copy the test_file to the uncompilable/com/example directory
        os.system(f"cp {path}/{test_file} ./uncompilable/com/example/")

    def create_init_file(self,src_file):
        init_file_content = f"""srcml com/example/{src_file} > {src_file}.xml
        mv {src_file}.xml com/example/
        """
        with open('./uncompilable/init_bug.sh','w') as init_file:
            init_file.write(init_file_content)
        
        # run the init file
        os.chdir('./uncompilable')
        os.system("bash ./init_bug.sh")
        os.chdir('..')

    def create_scenario_file(self,src_file,test_file, junit_version, mutation_operators, algorithm):
        if junit_version == 'JUnit 4':
            junit_file = 'junit-4.10.jar'
            compile_cmd = f"javac -cp {junit_file} com/example/{src_file} com/example/{test_file}"
            test_cmd = f"java -cp {junit_file}:. org.junit.runner.JUnitCore com.example.{test_file.split('.')[0]}"
        else:
            junit_file = 'junit-platform-console-standalone-1.7.2-all.jar'
            compile_cmd = f"javac -cp {junit_file} com/example/{src_file} com/example/{test_file}"
            test_cmd = f"java -jar junit-platform-console-standalone-1.7.2-all.jar --class-path . --select-class=com.example.{test_file.split('.')[0]}"
        
        scenario_file_content = \
        f"""
    [magpie]
    default_lengthout = 1e5

    [software]
    path = uncompilable/
    target_files =
        com/example/{src_file.split('.')[0]}.java.xml
    fitness = repair

    init_cmd = bash init_bug.sh
    compile_cmd = {compile_cmd}
    test_cmd = {test_cmd}

    [search]
    target_fitness = 0
    algorithm = {algorithm}
    max_steps = 20
    max_time = 120
    possible_edits =
        {mutation_operators[0]}
        {mutation_operators[1] if 1<len(mutation_operators) else ''}
        {mutation_operators[2] if 2<len(mutation_operators) else ''}

    [search.gp]
    pop_size = 100
        """
        with open('./uncompilable/_magpie/scenario.txt','w') as scenario_file:
            scenario_file.write(scenario_file_content)

    def setup(self,path,src_file,test_file, junit_version, mutation_operators,algorithm):
        self.clean()
        self.copy_files(path,src_file,test_file)
        self.create_init_file(src_file)
        self.create_scenario_file(src_file,test_file, junit_version, mutation_operators,algorithm)


if __name__ == "__main__":
    arg1 = sys.argv[1]
    arg2 = sys.argv[2]
    
    ms = MagpieSetup()
    ms.setup('./processed_dataset/llm_translations/train/run_2', arg1, arg2, 'JUnit 5', ['SrcmlStmtDeletion' ,'SrcmlStmtInsertion', 'SrcmlStmtReplacement'], 'GeneticProgrammingUniformConcat')