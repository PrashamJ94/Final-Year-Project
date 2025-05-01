
from math import sqrt
from collections import defaultdict

def gcd(a, b):
    return b if not a % b else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def get_prime_factors(n):
    res = defaultdict(int)
    i = 2
    while i * i <= n:
        while n % i == 0:
            res[i] += 1
            n //= i
        i += 1
    if n != 1:
        res[n] = 1
    return res

def is_prime_number(num):
    if num <= 2:
        return True
    elif num % 2 == 0:
        return False

    sqrt_num = sqrt(num)
    i = 3
    while i <= sqrt_num:
        if num % i == 0:
            return False
        i += 2

    return True

def modinv(a, m):
    b, u, v = m, 1, 0
    while b:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u

def main():
    N, K = map(int, input().split())
    A = [0] + [int(x) for x in input().split()]

    cur = 1
    dic = [-1] * (N + 1)
    flg = False

    for i in range(1, K + 1):
        if dic[cur] < 0 or flg:
            dic[cur] = i
            cur = A[cur]
        elif not flg:
            tmp = K - (dic[cur] - 1)
            tmp %= i - dic[cur]
            i = K - tmp
            flg = True

    print(cur)

if __name__ == '__main__':
    main()

#
