import sys
from io import StringIO
import atexit, os
from collections import Counter, deque
from itertools import permutations
from fractions import gcd
import math
from collections import deque
import heapq
from sys import stdin
import threading
import time

def main():
    n = int(input().strip())
    data = list(map(int, input().strip().split()))
    pre = [0] * (n + 1)

    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + data[i - 1]

    min_val = 1e18

    for i in range(1, n):
        val1 = pre[i]
        val2 = pre[n] - pre[i]

        min_val = min(min_val, abs(val1 - val2))

    print(min_val)

main()


