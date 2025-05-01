import math
import sys

def maxInt(a, b):
    return max(a, b)

def minInt(a, b):
    return min(a, b)

def absInt(a):
    return abs(a)

def absFloat64(a):
    return abs(a)

def maxFloat64(a, b):
    return max(a, b)

def minFloat64(a, b):
    return min(a, b)

def str2Int(s):
    return int(s)

def reverse(s):
    return s[::-1]

def powInt(p, q):
    return p ** q

def isPrime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    b = True
    rootx = int(math.sqrt(x))
    i = 3
    while i <= rootx:
        if x % i == 0:
            b = False
            break
        i += 2
    return b

def PrimeFactors(n):
    pfs = []

    while n % 2 == 0:
        pfs.append(2)
        n = n // 2

    i = 3
    while i * i <= n:
        while n % i == 0:
            pfs.append(i)
            n = n // i
        i += 2

    if n > 2:
        pfs.append(n)

    return pfs

def PrimeFactorsMap(n):
    pfs = {}

    while n % 2 == 0:
        if 2 in pfs:
            pfs[2] += 1
        else:
            pfs[2] = 1
        n = n // 2

    i = 3
    while i * i <= n:
        while n % i == 0:
            if i in pfs:
                pfs[i] += 1
            else:
                pfs[i] = 1
            n = n // i
        i += 2

    if n > 2:
        if n in pfs:
            pfs[n] += 1
        else:
            pfs[n] = 1

    return pfs

def sumInts(x):
    return sum(x)

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(x, y):
    return x * y // gcd(x, y)

def main():
    N, M = map(int, input().split())
    tmp = minInt(N, M // 2)
    ans = 0
    ans += tmp
    N -= tmp
    M -= tmp * 2
    print(ans + M // 4)

if __name__ == "__main__":
    main()


