import sys
from collections import deque
from typing import List, Tuple

mod = 1000000007

def mod_pow(r: int, n: int) -> int:
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod
        s = (s * s) % mod
        n >>= 1
    return t

def merge(a: List[Tuple[int, int]], n: int) -> Tuple[int, int]:
    one = 0
    zero = 1
    total = 1
    for i in range(n):
        one = (one * a[i][1] + zero * a[i][0]) % mod
        zero = (zero * a[i][1]) % mod
        total = (total * (a[i][1] + a[i][0])) % mod
    return (one, (total + mod - one) % mod)

def get_at(d: deque, x: int) -> Tuple[int, int]:
    return d[x]

def assign_at(d: deque, x: int, v: Tuple[int, int]) -> None:
    d[x] = v

def run() -> None:
    n = int(input())
    p = [0] * (n + 1)
    depth = [0] * (n + 1)
    cnt = [0] * (n + 1)
    cnt[0] = 1
    g = [deque([]) for _ in range(n + 1)]
    for i in range(1, n + 1):
        p[i] = int(input())
        g[p[i]].append(i)
        depth[i] = depth[p[i]] + 1
        cnt[depth[i]] += 1
    dp = [deque([(1, 1)]) for _ in range(n + 1)]
    child = [deque([]) for _ in range(n + 1)]
    lst = [(0, 0)] * (n + 1)
    for i in range(n, -1, -1):
        v = i
        if not g[v]:
            continue
        len_child = len(g[v])
        for u in g[v]:
            child[len_child - 1] = dp[u]
            len_child -= 1
        if len(child) > 1:
            child.sort(key=len, reverse=True)
            for d in range(len(child[1])):
                j = 0
                while j < len(child) and d < len(child[j]):
                    lst[j] = get_at(child[j], d)
                    j += 1
                assign_at(child[0], d, merge(lst, j))
            for j in range(1, len(child)):
                child[j].clear()
        dp[v] = child[0]
        dp[v].appendleft((1, 1))
    ans = 0
    for i in range(len(dp[0])):
        ans += mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i)[0] % mod
    print(ans % mod)

def main() -> None:
    run()

if __name__ == "__main__":
    main()


