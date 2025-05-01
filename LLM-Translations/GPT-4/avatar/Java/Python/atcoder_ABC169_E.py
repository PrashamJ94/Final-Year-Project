import sys
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter
from itertools import permutations, combinations
from heapq import heappush, heappop
from math import ceil, sqrt, gcd
from operator import itemgetter
from functools import reduce

def main():
    num = 998244353
    n = int(input())
    ai = []
    bi = []
    for _ in range(n):
        a, b = map(int, input().split())
        ai.append(a)
        bi.append(b)
    ai.sort()
    bi.sort()

    if n % 2 == 1:
        print(bi[n // 2] - ai[n // 2] + 1)
    else:
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        print(int(2 * (c - b) + 1))

if __name__ == '__main__':
    main()


