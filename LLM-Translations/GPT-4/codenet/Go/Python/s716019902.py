import sys
from functools import reduce

mod = 998244353
facNum = 300001

def main():
    N = int(input())
    sum = 0
    for i in range(1, N+1):
        if i % 3 == 0 or i % 5 == 0:
            continue
        sum += i
    print(sum)

def Pow(a, n):
    ans = 1
    while n > 0:
        if (n & 1) == 1:
            ans = ans * a % mod
        a = a * a % mod
        n = n >> 1
    return ans

def Gcd(a, b):
    if a < b:
        return Gcd(b, a)
    while b != 0:
        a, b = b, a % b
    return a

def min(a, b):
    if a < b:
        return a
    return b

def combination(n, k, fac, ifac):
    if n < k or n < 0:
        return 0
    if k == 0:
        return 1
    ans = ifac[k] * ifac[n-k] % mod
    return ans * fac[n] % mod

def factorial():
    fac = [1] * facNum
    ifac = [1] * facNum
    for i in range(1, facNum):
        fac[i] = fac[i-1] * i % mod
        ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod
    return fac, ifac

def lowerBound(vs, v):
    n = len(vs) // 2
    m = len(vs)
    while m != n:
        if vs[n] < v:
            n = (m-n+1) // 2 + n
        else:
            m = n
            n = n // 2
    return n

def IntSlice(n, init):
    return [init] * n

if __name__ == "__main__":
    main()


