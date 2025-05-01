import sys
from sys import stdin

def main():
    n = int(input().strip())
    a, b, c = 0, 0, 0
    
    a_values = list(map(int, input().strip().split()))
    b_values = list(map(int, input().strip().split()))
    c_values = list(map(int, input().strip().split()))
    
    a = sum(a_values)
    b = sum(b_values)
    c = sum(c_values)
    
    x = a - b
    y = b - c
    
    print(x)
    print(y)

if __name__ == "__main__":
    main()


