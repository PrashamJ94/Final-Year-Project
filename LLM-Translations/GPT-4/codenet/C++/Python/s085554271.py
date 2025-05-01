
from math import sqrt, floor
from itertools import product

def isPrime(num):
    if num < 2:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False

    sqrtNum = sqrt(num)
    for i in range(3, int(sqrtNum) + 1, 2):
        if num % i == 0:
            return False
    return True

def gcd(a, b):
    return b if b != 0 else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def Max(a, b, c):
    return max(a, max(b, c))

def Min(a, b, c):
    return min(a, min(b, c))

def integer(num):
    return floor(num) == num

def fact(num):
    return 1 if num == 0 else num * fact(num - 1)

def yakusu(n):
    cnt = 0
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            cnt += 1
            if i * i != n:
                cnt += 1
    return cnt

def main():
    k, a, b = map(int, input().split())
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            return
    print("NG")

if __name__ == "__main__":
    main()


