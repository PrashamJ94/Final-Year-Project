import sys
from decimal import Decimal, ROUND_HALF_UP

def main():
    num_str = sys.stdin.readline().strip()
    num = Decimal(num_str)

    if '9' in num_str:
        print("GOTO Vasilisa.")
    else:
        rounded_num = num.quantize(Decimal('1.'), rounding=ROUND_HALF_UP)
        print(int(rounded_num))

if __name__ == "__main__":
    main()


