import sys
from typing import List, Tuple

def main():
    N = int(input())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    index = 0
    max_diff = sys.maxsize
    for i in range(1, N):
        if max_diff > abs(A[0] - 2 * A[i]):
            max_diff = abs(A[0] - 2 * A[i])
            index = i
    print(A[0], A[index])

if __name__ == "__main__":
    main()


