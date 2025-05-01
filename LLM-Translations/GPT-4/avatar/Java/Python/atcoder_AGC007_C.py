import sys
from decimal import Decimal, getcontext

getcontext().prec = 100

def main():
    N, d, x = map(Decimal, sys.stdin.readline().split())
    ans = Decimal("0.0")
    while N > 0.5:
        adnum = d + x * (N - Decimal("0.5"))
        ans += adnum
        d = (N + Decimal("1.0")) * d / N + (Decimal("5.0") * x) / (Decimal("2.0") * N)
        x = (Decimal("1.0") + (Decimal("2.0") / N)) * x
        N -= 1

    print(f'{ans:.20f}')

main()


