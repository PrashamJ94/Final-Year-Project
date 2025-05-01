import sys
from typing import List, Dict, Union
import heapq

def main():
    n = int(input().strip())
    arr = list(map(float, input().split()))
    heapq.heapify(arr)
    prev = heapq.heappop(arr)
    for _ in range(1, len(arr)):
        cur = heapq.heappop(arr)
        prev = (prev + cur) / 2

    print(prev)

main()


