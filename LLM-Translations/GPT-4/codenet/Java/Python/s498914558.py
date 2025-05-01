import sys
from functools import reduce
from itertools import accumulate
from collections import deque, defaultdict, Counter
import bisect
import heapq
import math
import random
import re
import string
import copy
import time
import operator

def main():
    n, m = map(int, input().split())
    po = list(map(int, input().split()))
    m -= sum(po)
    po.sort()
    print(n + m // po[0])

if __name__ == "__main__":
    main()


