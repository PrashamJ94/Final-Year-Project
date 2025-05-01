import sys
from math import gcd

def fast_pow(base, n, M):
    if n == 0:
        return 1
    if n == 1:
        return base
    halfn = fast_pow(base, n // 2, M)
    if n % 2 == 0:
        return (halfn * halfn) % M
    else:
        return (((halfn * halfn) % M) * base) % M

def modInverse(n, M):
    return fast_pow(n, M - 2, M)

def solve():
    t = 1
    for _ in range(t):
        n, m = map(int, input().split())
        if n == 0:
            print(0)
            continue
        if n == m:
            print(0)
            continue
        if n > m:
            n = m + n % m
            n -= m
            print(min(m - n, n))
            continue
        print(min(m - n, n))

if __name__ == "__main__":
    solve()



