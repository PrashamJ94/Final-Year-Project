
import sys
import math
from typing import List, Tuple

def main():
    N = int(input())

    if N % 10 in [2, 4, 5, 7, 9]:
        print("hon")
    elif N % 10 in [0, 1, 6, 8]:
        print("pon")
    elif N % 10 == 3:
        print("bon")

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False

    return True

def calc_gcd(x: int, y: int) -> int:
    if y == 0:
        return x
    elif x >= y:
        return calc_gcd(y, x % y)
    else:
        return calc_gcd(x, y % x)

def get_divisor(n: int) -> List[int]:
    divisor = {1}
    if n != 1:
        divisor.add(n)

    sqrt_n = int(math.sqrt(n))
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n // i)

    return list(divisor)

def fact_mod(n: int) -> int:
    value = 1
    mod = 1e9 + 7
    for _ in range(1, n + 1):
        value = (value * n) % mod
        n -= 1
    return value

def combination_mod(n: int, k: int) -> int:
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_nk = fact_mod(n - k)
    mod = 1e9 + 7
    fact_kr = pow(fact_k, mod - 2, mod)
    fact_nkr = pow(fact_nk, mod - 2, mod)
    return (fact_n * ((fact_kr * fact_nkr) % mod)) % mod

def prime_factors(n: int) -> List[int]:
    factors = []
    i = 2
    while i * i <= n:
        r = n % i
        if r != 0:
            i += 1
        elif r == 0:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

if __name__ == '__main__':
    main()


#
