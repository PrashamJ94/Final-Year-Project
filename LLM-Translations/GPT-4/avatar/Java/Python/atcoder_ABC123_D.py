import heapq
from sys import stdin

def main():
    x = [int(e) for e in stdin.readline().split()]
    k = int(input())
    a = [sorted([int(e) for e in stdin.readline().split()]) for _ in range(3)]
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][-i - 1] + a[1][-j - 1] + a[2][-m - 1]
                    heapq.heappush(ans, -tmp)
                else:
                    break
    for _ in range(k):
        print(-heapq.heappop(ans))

main()


