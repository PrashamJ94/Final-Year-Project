import sys
from decimal import Decimal

def main():
    a, b = map(Decimal, sys.stdin.readline().split())
    mul = a * b
    print(int(mul))

if __name__ == "__main__":
    main()


