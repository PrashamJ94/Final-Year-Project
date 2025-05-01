import sys
from typing import List

class UnionFindTree:
    def __init__(self, n: int):
        self.n = n
        self.par = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x: int) -> int:
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x: int, y: int):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

def atcoder_ABC126_E(n: int, m: int, xyz: List[List[int]]) -> int:
    utf = UnionFindTree(n)

    for x, y, z in xyz:
        utf.unite(x - 1, y - 1)

    cnt = 0
    for i in range(n):
        if utf.par[i] == i:
            cnt += 1

    return cnt

if __name__ == "__main__":
    input = sys.stdin.readline
    n, m = map(int, input().split())
    xyz = [list(map(int, input().split())) for _ in range(m)]
    print(atcoder_ABC126_E(n, m, xyz))


