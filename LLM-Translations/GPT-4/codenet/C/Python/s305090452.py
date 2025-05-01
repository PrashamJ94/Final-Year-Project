
import heapq
from typing import List, Tuple

class UnionFind:
    def __init__(self, size: int):
        self.parent = [-1] * size
        self.size = size

    def root(self, x: int) -> int:
        index = []
        while self.parent[x] >= 0:
            index.append(x)
            x = self.parent[x]
        for i in index:
            self.parent[i] = x
        return x

    def same(self, x: int, y: int) -> bool:
        return self.root(x) == self.root(y)

    def get_size(self, x: int) -> int:
        return -self.parent[self.root(x)]

    def unite(self, x: int, y: int):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        if self.parent[x] > self.parent[y]:
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x

def solve(n: int, d: int, a: List[int]) -> int:
    p = sorted(enumerate(a), key=lambda x: x[1], reverse=True)
    l = [(a[i] + (n - 1 - i) * d, i) for i in range(n)]
    r = [(a[i] + i * d, i) for i in range(n)]
    heapq.heapify(l)
    heapq.heapify(r)
    h = []
    for v, val in p:
        if v > 0:
            t = heapq.heappop(l)
            heapq.heappush(h, (val + t[0] - (n - 1 - v) * d, (v, t[1])))
            heapq.heappush(l, t)
        if v + 1 < n:
            t = heapq.heappop(r)
            heapq.heappush(h, (val + t[0] - v * d, (v, t[1])))
            heapq.heappush(r, t)
        heapq.heappush(l, (float("inf"), v))
        heapq.heappush(r, (float("inf"), v))
    heapq.heapify(h)
    sum = 0
    u = UnionFind(n)
    while u.get_size(0) < n:
        c, e = heapq.heappop(h)
        if u.same(e[0], e[1]):
            continue
        u.unite(e[0], e[1])
        sum += c
    return sum

def main():
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    print(solve(n, d, a))

if __name__ == "__main__":
    main()


#
