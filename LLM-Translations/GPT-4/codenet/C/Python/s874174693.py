import sys
from functools import reduce

def swap(x, y):
    return y, x

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def upll(a, b):
    return -1 if a < b else 1 if a > b else 0

def downll(a, b):
    return 1 if a < b else -1 if a > b else 0

def sortup(a):
    return sorted(a, key=lambda x: x, reverse=False)

def sortdown(a):
    return sorted(a, key=lambda x: x, reverse=True)

def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n //= 2
    return ans

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

def max(a, b):
    return b if a < b else a

def min(a, b):
    return a if a < b else b

def chmax(a, b):
    return max(a, b)

def chmin(a, b):
    return min(a, b)

def main():
    n = int(input().strip())
    sum_digits = sum([int(d) for d in str(n)])
    if n % sum_digits == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


