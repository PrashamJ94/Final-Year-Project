import sys
from typing import List

mod = int(1e9) + 7

def main():
    N = int(input().strip())
    to = [[] for _ in range(N)]
    edges = [[0, 0] for _ in range(N-1)]
    
    for _ in range(N-1):
        A, B = map(lambda x: int(x)-1, input().strip().split())
        to[A].append(B)
        to[B].append(A)
        edges[_][0] = B
        edges[_][1] = A
        
    dp = [0] * N
    rec(0, -1, dp, to)
    mulsum = 0
    
    for e in edges:
        candidate1 = e[0]
        candidate2 = e[1]
        child = candidate1
        if dp[candidate1] > dp[candidate2]:
            child = candidate2
        
        a = dp[child]
        b = N - a
        
        mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
        mulsum += mul
        mulsum %= mod
        
    cases = modpow(2, N)
    PN = (mulsum + (cases - 1 + mod) % mod) % mod
    BN = N * modpow(2, N-1) % mod
    WN = (PN - BN + mod) % mod
    ans = WN * modpow(cases, mod-2)
    ans %= mod
    
    print(ans)
    
def rec(v: int, parent: int, dp: List[int], to: List[List[int]]) -> int:
    res = 1
    for next in to[v]:
        if next == parent:
            continue
        res += rec(next, v, dp, to)
    dp[v] = res
    return res

def modpow(x: int, y: int) -> int:
    if y == 0:
        return 1
    if y % 2 != 0:
        return x * modpow(x, y-1) % mod
    tmp = modpow(x, y//2)
    return tmp * tmp % mod

if __name__ == "__main__":
    main()


