import sys
from typing import List

def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    A.sort()
    
    for j in range(1, N):
        if A[j] == A[j-1]:
            print("NO")
            sys.exit(0)
            
    print("YES")

if __name__ == '__main__':
    main()


