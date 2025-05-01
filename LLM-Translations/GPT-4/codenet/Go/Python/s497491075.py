import sys
import math

def main():
    input_data = sys.stdin.readlines()
    N, D = map(int, input_data[0].split())
    
    count = 0
    for line in input_data[1:]:
        x, y = map(int, line.split())
        d = math.sqrt(x * x + y * y)
        if D >= d:
            count += 1
    
    print(count)

if __name__ == "__main__":
    main()


