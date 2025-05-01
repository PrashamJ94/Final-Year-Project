import sys
from collections import defaultdict, deque
from heapq import *
from math import ceil
from itertools import permutations
from itertools import combinations
from collections import Counter
from fractions import gcd
from bisect import bisect_left, bisect_right
from functools import cmp_to_key

input=sys.stdin.readline
def ii():return int(input().strip())
def li():return list(map(int,input().split()))
def lf():return list(map(float,input().split()))

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        min1 = min(self.x, self.y)
        min2 = min(other.x, other.y)
        if min1 != min2:
            return min1 < min2
        if self.x == other.x:
            return self.y < other.y
        return self.x < other.x

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

def main():
    n = ii()
    arr = sorted(li(), reverse=True)
    if n >= 3:
        d = defaultdict(int)
        ans = arr[0] + arr[1]
        d[Pair(arr[0], arr[1])] += 1
        p1, p2 = Pair(arr[2], arr[1]), Pair(arr[2], arr[0])
        d[p1] += 1
        d[p2] += 1
        for i in range(3, n):
            p = min(d.keys())
            d[p] -= 1
            if d[p] == 0:
                del d[p]
            ans += min(p.x, p.y)
            d[Pair(p.x, arr[i])] += 1
            d[Pair(p.y, arr[i])] += 1
        print(ans)
    else:
        print(arr[0])

main()

