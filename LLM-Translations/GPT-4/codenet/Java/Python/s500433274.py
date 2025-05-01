import sys
from BigInteger import BigInteger

def main():
    for line in sys.stdin:
        a, b = map(BigInteger, line.strip().split())
        c = max(a, b)
        if a == c and b != c:
            print("GREATER")
        elif b == c and a != c:
            print("LESS")
        else:
            print("EQUAL")

if __name__ == "__main__":
    main()


