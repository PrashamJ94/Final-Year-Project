import sys
from io import StringIO
import math

class Main:
    def __init__(self):
        self.constraints = []
        self.N = int(input().strip())
        for _ in range(5):
            self.constraints.append(int(input().strip()))
        self.calc()

    def calc(self):
        min_value = sys.maxsize
        for c in self.constraints:
            min_value = min(min_value, c)
        time = self.N // min_value
        if self.N % min_value != 0:
            time += 1
        time += 4
        self.result = time

if __name__ == "__main__":
    ins = Main()
    print(ins.result)


