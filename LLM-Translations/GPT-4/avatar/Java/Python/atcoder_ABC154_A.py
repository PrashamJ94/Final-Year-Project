
import sys
from io import StringIO

def main():
    input = sys.stdin.readline
    str = input().split()
    a, b = map(int, input().split())
    u = input().strip()
    print(f"{a - 1 if u == str[0] else a} {b if u == str[0] else b - 1}")

if __name__ == "__main__":
    main()


##End of Code
