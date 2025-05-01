
import sys
import math
from functools import reduce
from collections import defaultdict, deque

def find(n, N, p):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

def solve():
    X, N, *p = map(int, sys.stdin.buffer.read().split())

    for i in range(101):
        if find(X-i, N, p) == 1:
            print(X-i)
            sys.exit(0)
        if find(X+i, N, p) == 1:
            print(X+i)
            sys.exit(0)

if __name__ == '__main__':
    solve()


