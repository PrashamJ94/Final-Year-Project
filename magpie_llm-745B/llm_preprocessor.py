import re
from groq import Groq
from openai import OpenAI
from dotenv import load_dotenv
import os
import sys

class LLMPreprocessor:
    # src_file, test_file are absolute paths
    def __init__(self,files,path):
        self.files = files
        self.path = path
        self.model_name = "gpt-4o-mini"
        self.temp = 0.7
        load_dotenv()
        self.model = OpenAI()
        self.prompt = """
        You are assigned the role of a syntax error fixer for Java program files. I want you to find any syntax errors in the following code and return only the fixed Java program, with no additional text. The returned output should only contain the fixed code. Do not provide any other text in your output.

Make sure to:
- Convert method names to camel case.
- Make the methods static if they are not annotated with @Test.
- Fix any missing import statements.
- If the code does not have a class declaration, name the class as {file_name}.

Here's the code for the Java program:
<code>
{code}
</code>
        """
    
    def run(self):
        for file in self.files:
            self.preprocess(file)
            print(f"✅Preprocessed {file} and wrote to path")
    
    def get_code(self, returned_str):
        pattern = r"```java\s*([\s\S]*?)\s*```"
        match = re.search(pattern, returned_str)
    
        if match:
            return match.group(1).strip()
        
    def preprocess(self,file):
        file_str = self.read_java_file(file)
        file_name = file.split('.')[0]
        prompt = self.prompt.format(file_name=file_name, code=file_str)
        
        returned_file_str = self.get_code(self.send_prompt(prompt))
        self.write_java_file(file,returned_file_str)
    
    def read_java_file(self,filename):
        with open(self.path + filename,'r') as java_file:
            contents = java_file.read()
        
        return contents
    
    def write_java_file(self,filename,content):
        with open(self.path + filename,'w') as java_file:
            java_file.write(content)
        return

    def send_prompt(self, prompt):
        response = self.model.chat.completions.create(
            model=self.model_name,
            messages=[{"role": "user", "content": prompt}] if isinstance(prompt, str) else prompt,
            temperature=self.temp)
        return response.choices[0].message.content

if __name__ == "__main__":
    src_file = sys.argv[1]
    test_file = sys.argv[2]
    llm = LLMPreprocessor(f'./uncompilable/com/example/{src_file}',f'./uncompilable/com/example/{test_file}')
    llm.run()