import sys
from collections import deque
from heapq import heappush, heappop

def main():
    N, M = map(int, input().split())
    list = [deque() for _ in range(100001)]

    for _ in range(N):
        a, b = map(int, input().split())
        list[a].append(b)

    res = 0
    pqueue = []
    for i in range(1, M + 1):
        if list[i]:
            for b in list[i]:
                heappush(pqueue, -b)
        if pqueue:
            res += -heappop(pqueue)

    print(res)

if __name__ == "__main__":
    main()


