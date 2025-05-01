import sys
from decimal import Decimal

def main():
    sa = input().strip()
    sb = input().strip()
    A = Decimal(sa)
    B = Decimal(sb)
    result = A * B
    print(result.to_integral_value())

if __name__ == '__main__':
    main()


