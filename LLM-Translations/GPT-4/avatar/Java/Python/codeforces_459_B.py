import sys
from typing import List

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))

    A.sort()

    min_val = A[0]
    max_val = A[N - 1]
    mins = 0
    maxs = 0

    for value in A:
        if value == min_val:
            mins += 1
        if value == max_val:
            maxs += 1

    if min_val == max_val:
        print((max_val - min_val), mins * (mins - 1) // 2)
    else:
        print((max_val - min_val), mins * maxs)

if __name__ == "__main__":
    main()


