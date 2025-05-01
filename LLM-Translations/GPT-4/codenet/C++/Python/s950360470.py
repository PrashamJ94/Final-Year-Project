import sys
from functools import reduce

MOD = 1000000007

def pow_mod(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

def mod_inv(a, mod):
    return pow_mod(a, mod - 2, mod)

def mod_nCk(n, k, mod):
    if n == 0 or k == 0:
        return 1
    p = reduce(lambda x, y: x * y % mod, range(n - k + 1, n + 1))
    q = reduce(lambda x, y: x * y % mod, range(2, k + 1))
    q = mod_inv(q, MOD)
    return (p * q) % MOD

def main():
    n, k = map(int, sys.stdin.readline().split())
    print(mod_nCk(n, k, MOD))

main()


