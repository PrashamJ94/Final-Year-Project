import re
import subprocess
class RunJavaTests:
    def __init__(self, src_file, test_file, path):
        self.src_file = src_file
        self.test_file = test_file
        self.path = path
        self.junit_version = None

    def detect_junit_version(self, test_file):
        with open(self.path + test_file, 'r') as f:
            for line in f:
                if 'org.junit.jupiter' in line:
                    return 'JUnit 5'
               
        
        return 'JUnit 4'
    
    def compile_file(self,file):
        self.junit_version = self.detect_junit_version(self.test_file)
        if self.junit_version == 'JUnit 5':
            compile_cmd = ["javac", "-cp", "junit-platform-console-standalone-1.7.2-all.jar:tmp",
                           self.path + file]
            
        else:
            compile_cmd = ["javac", "-cp", "junit-4.10.jar:tmp",
                           self.path + file]
        
        compile_process = subprocess.run(
            compile_cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        return compile_process.returncode, compile_process.stderr, compile_process.stdout
        
    def compile(self):
        compile_code = 0
        error_files = []
        stderrs = []
        stdouts = []
        for file in [self.src_file, self.test_file]:
            compile_c, stderr, stdout = self.compile_file(file)
            if compile_c:
                compile_code = 1
                error_files.append(file)
            if stderr:
                stderrs.append(stderr)
            if stdout:
                stdouts.append(stdout)
        
        return compile_code,error_files, stderrs, stdouts

    def run_tests(self):
        if not self.junit_version:
            self.junit_version = self.detect_junit_version(self.test_file)
        
        if self.junit_version == 'JUnit 5':
            run_cmd = ["java" ,"-jar", "junit-platform-console-standalone-1.7.2-all.jar", "--class-path", "tmp", "--select-class", f"com.example.{self.test_file.split('.')[0]}"]
        else:
            run_cmd = ["java", "-cp", "junit-4.10.jar:tmp", "org.junit.runner.JUnitCore", f"com.example.{self.test_file.split('.')[0]}"]
        
        try:
            run_process = subprocess.run(
                run_cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=60  # 60-second timeout
            )
        except subprocess.TimeoutExpired:
            print(f"Test run timed out for {self.test_file}")
            return 1, 'Test run timed out', [], []
        
        
        # process the results
        if run_process.returncode != 0:
            
            if self.junit_version == 'JUnit 4':
                pattern = pattern = r"Tests run: (\d+),\s+Failures: (\d+)(?:,\s+Errors: (\d+))?"
                match = re.search(pattern, run_process.stdout)
                if match:
                    tests_run = int(match.group(1))
                    failures = int(match.group(2))
                    return run_process.returncode, 'Tests run: {}, Failures: {}'.format(tests_run, failures), run_process.stdout, run_process.stderr
            else:
                # JUnit 5 pattern
                pattern = r"\[[\s]+(\d+) tests found[\s]+\][\s\S]*?\[[\s]+(\d+) tests successful[\s]+\][\s\S]*?\[[\s]+(\d+) tests failed[\s]+\]"
                match = re.search(pattern, run_process.stdout, re.DOTALL)
                if match:
                    tests_found = int(match.group(1))
                    tests_successful = int(match.group(2))
                    tests_failed = int(match.group(3))
                    return run_process.returncode, 'Tests run: {}, Tests failed: {}'.format(tests_found, tests_failed), run_process.stdout, run_process.stderr
                
        
        return run_process.returncode, 'All tests passed', [run_process.stdout], [run_process.stderr]
    