import sys
from typing import List

def main():
    N = int(input())
    X = list(map(int, input().split()))
    Y = X.copy()

    Y.sort()

    y = Y[N//2]
    for i in range(N):
        if X[i] < Y[N//2]:
            print(Y[N//2], end=" ")
        else:
            print(Y[N//2 - 1], end=" ")
    print()

main()

