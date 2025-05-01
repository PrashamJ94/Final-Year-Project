Here is the Python code:


from fractions import gcd
from functools import reduce

def lcm(a, b):
    return a * b // gcd(a, b)

def mod_inv(x, mod):
    return pow(x, mod - 2, mod)

def mod_div(a, b, mod):
    return a % mod * mod_inv(b, mod) % mod

N = int(input())
A = list(map(int, input().split()))
lcm_val = reduce(lcm, A)
mod = 10 ** 9 + 7
mod_lcm = lcm_val % mod
ans = sum(mod_div(mod_lcm, a, mod) for a in A) % mod

print(ans)

##End of Code
