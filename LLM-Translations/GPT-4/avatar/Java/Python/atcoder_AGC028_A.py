import math
from functools import reduce
from fractions import gcd

def main():
    n, m = map(int, input().split())
    s = input()
    t = input()
    gcd_nm = math.gcd(n, m)
    lc = (n * m) // gcd_nm

    for k in range(gcd_nm):
        if s[k * n // gcd_nm] != t[k * m // gcd_nm]:
            print(-1)
            return

    print(lc)

if __name__ == "__main__":
    main()


