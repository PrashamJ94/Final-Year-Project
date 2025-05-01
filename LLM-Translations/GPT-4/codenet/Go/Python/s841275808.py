import sys
from typing import List, Tuple

def main():
    N = int(input().strip())
    X = list(map(int, input().strip().split()))
    Y = sorted(X)
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]
    for i in range(N):
        if X[i] <= m1:
            print(m2)
        else:
            print(m1)

if __name__ == "__main__":
    main()


