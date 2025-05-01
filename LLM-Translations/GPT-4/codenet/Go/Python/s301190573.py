import sys
from typing import List, Tuple

sys.setrecursionlimit(1000000)

def next_line() -> str:
    return input().strip()

def next_ints() -> Tuple[int, int]:
    x, y = map(int, next_line().split())
    return x, y

def next_int_array() -> List[int]:
    a = list(map(int, next_line().split()))
    return [i - 1 for i in a]

par = []
rank = []

def main():
    global par, rank
    n, m = next_ints()
    p = next_int_array()

    initialize(n)
    
    for _ in range(m):
        x, y = next_ints()
        unite(x - 1, y - 1)

    s = 0
    for i in range(n):
        if same(i, p[i]):
            s += 1

    print(s)

def initialize(n: int):
    global par, rank
    par = [i for i in range(n)]
    rank = [0] * n

def root(i: int) -> int:
    global par
    if par[i] == i:
        return i
    par[i] = root(par[i])
    return par[i]

def same(i: int, j: int) -> bool:
    return root(i) == root(j)

def unite(i: int, j: int):
    global par, rank
    i = root(i)
    j = root(j)
    if i == j:
        return
    if rank[i] < rank[j]:
        par[i] = j
    else:
        par[j] = i
        if rank[i] == rank[j]:
            rank[i] += 1

if __name__ == "__main__":
    main()


