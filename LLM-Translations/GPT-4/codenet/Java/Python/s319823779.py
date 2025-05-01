import sys
from itertools import product

def main():
    a, b, c, x = map(int, sys.stdin.readline().split())

    res = 0

    for i, j, k in product(range(a + 1), range(b + 1), range(c + 1)):
        total = 500 * i + 100 * j + 50 * k

        if total == x:
            res += 1

    print(res)

main()

