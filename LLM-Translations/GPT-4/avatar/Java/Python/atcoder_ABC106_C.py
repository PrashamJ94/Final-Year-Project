import sys
from io import StringIO
import atexit, io, sys

buffer = io.StringIO()
sys.stdout = buffer
@atexit.register
def write():
    sys.__stdout__.write(buffer.getvalue())

def main():
    input_str = input().strip()
    k = int(input().strip())
    n = len(input_str)

    for i in range(k):
        if input_str[i] == '1':
            if i == k - 1:
                print(1)
                return
        else:
            print(input_str[i])
            return

main()

