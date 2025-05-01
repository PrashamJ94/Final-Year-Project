import re
import sys
import time

class JavaTestsConstruction:
    def __init__(self, src_file, test_file):
        self.src_file = src_file
        self.test_file = test_file
        self.path = '../dataset/evalplus/Python/TestCases/'
        self.class_name = test_file.split(".")[0]
        self.cached_type = None

    def parse_test_case(self, line):
        match = re.search(r'self\.assertEqual\((.*)\)', line)
        if match:
            content = match.group(1).strip()
            
            # Identify the separating comma that is not inside brackets or quotes
            bracket_level = 0
            inside_quotes = False
            split_index = None

            for i, char in enumerate(content):
                if char == '"' and (i == 0 or content[i-1] != '\\'):  # Toggle inside quotes state
                    inside_quotes = not inside_quotes
                elif char == '[':
                    bracket_level += 1
                elif char == ']':
                    bracket_level -= 1
                elif char == ',' and bracket_level == 0 and not inside_quotes:
                    split_index = i
                    break

            if split_index is None:
                return None  # Invalid format
            
            expected_output_str = content[:split_index].strip()
            method_name = self.convert_to_camel_case(content[split_index+1:].strip())

            try:
            # Convert expected output to the appropriate type
                if expected_output_str.startswith("[") and expected_output_str.endswith("]"):
                    expected_output = eval(expected_output_str)  # Convert to list
                elif expected_output_str.replace(".", "", 1).isdigit():
                    expected_output = float(expected_output_str) if "." in expected_output_str else int(expected_output_str)
                else:
                    expected_output = expected_output_str.strip('"')
            except ValueError:
                return None

            if len(expected_output_str) > 1000:
                return None
        
            return expected_output, method_name

        return None


    def convert_to_camel_case(self, name):
        name = name.split('_')
        return name[0] + ''.join(word.capitalize() for word in name[1:])
    
    def generate_junit_tests(self,path):
        input_file = self.src_file.split(".")[0] + ".txt"
        output_file = self.test_file
        with open(self.path + input_file, 'r') as file:
            lines = file.readlines()
        
        test_cases = [self.parse_test_case(line) for line in lines if self.parse_test_case(line)]
        
        with open(path + output_file, 'w') as file:
            file.write("package com.example;\n\n")
            file.write("import static org.junit.Assert.*;\n")
            file.write("import org.junit.Test;\n")
            file.write("import java.util.*;\n\n")
            file.write(f"public class {self.class_name} {{\n\n")
            
            for i, (expected_output, method_name) in enumerate(test_cases):
                file.write(f"    @Test\n")
                file.write(f"    public void test_{i}() {{\n")
                if isinstance(expected_output, list):
                    # Check if the list contains only integers
                    if all(isinstance(item, int) for item in expected_output):
                        type_d = 'Integer'
                    elif all(isinstance(item, str) for item in expected_output):
                        # make sure all strings are enclosed in double quotes
                        type_d = 'Object'
                    else:
                        type_d = 'Object'
                    
                    expected_output = str(expected_output).replace("[", "(").replace("]", ")").replace("'", "\"")
                    file.write(f"        List<{type_d}> expected = Arrays.asList{expected_output};\n")
                elif isinstance(expected_output, (int, float)):
                    # check if number is larger than the largest integer in java
                    if expected_output > 2147483647:
                        expected_output = str(expected_output) + "L"
                    elif expected_output < -2147483648:
                        expected_output = str(expected_output) + "L"
                    file.write(f"        Object expected = {expected_output};\n")
                else:
                    file.write(f"        Object expected = \"{expected_output}\";\n")
                
                method_name = method_name.replace("'", "\"")
                # check the parameters of the method 
                param_start_index = method_name.find('(')
                
                param_string = method_name[param_start_index+1:-1]
                parameters = self.extract_parameters(param_string)
                method_name = method_name[:param_start_index+1]
                for i in range(len(parameters)):
                    param = parameters[i]
                    try:
                        
                        if isinstance(eval(param),list):
                            if not self.cached_type:
                                self.cached_type = self.get_d_type_list(eval(param))
                            file.write(f"       List <{self.cached_type}> input = Arrays.asList{str(param).replace('[', '(').replace(']', ')')};\n")
                            if i>=1:
                                method_name += ", "
                            method_name+= "input"
                        
                        else:
                            if i>=1:
                                method_name += ", "
                            method_name+=str(param)
                    except:
                        break
                        
                
                method_name+= ")"
                file.write(f"        assertEquals(expected, {self.src_file.split('.')[0]}.{method_name});\n")
                file.write("    }\n\n")
            
            file.write("}")
    
    def get_d_type_list(self,lst):
        if all(isinstance(item, int) for item in lst):
            return 'Integer'
        elif all(isinstance(item, str) for item in lst):
            return 'String'
        else:
            return 'Object'

    def extract_parameters(self,param_string):
        """Extract individual parameters from a parameter string."""
        parameters = []
        current_param = ""
        bracket_level = 0
        in_quotes = False
        
        for char in param_string:
            if char == '[' or char == '(':
                bracket_level += 1
                current_param += char
            elif char == ']' or char == ')':
                bracket_level -= 1
                current_param += char
            elif char == '"' or char == "'":
                in_quotes = not in_quotes
                current_param += char
            elif char == ',' and bracket_level == 0 and not in_quotes:
                # This is a parameter separator
                parameters.append(current_param.strip())
                current_param = ""
            else:
                current_param += char
    
    # Add the last parameter
        if current_param.strip():
            parameters.append(current_param.strip())
    
        return parameters

if __name__ == "__main__":
    src_file = sys.argv[1]
    test_file = sys.argv[2]
    java_test = JavaTestsConstruction(src_file, test_file)
    java_test.generate_junit_tests('./uncompilable/com/example/')