import sys
from io import StringIO
import heapq

def main():
    n, k = map(int, input().split())
    as_ = list(map(int, input().split()))
    as_ = [a - 1 for a in as_]

    lists = [[] for _ in range(n)]
    answer = 0

    for i in range(n):
        j = as_[i]
        if i > 0:
            lists[j].append(i)
        elif j > 0:
            answer += 1

    def dfs(a, pre):
        nonlocal answer
        h = 0
        for i in lists[a]:
            h = max(h, dfs(i, a))
        if pre > 0 and h == k - 1:
            h = 0
            answer += 1
        else:
            h += 1
        return h

    dfs(0, 0)
    print(answer)

if __name__ == "__main__":
    main()


