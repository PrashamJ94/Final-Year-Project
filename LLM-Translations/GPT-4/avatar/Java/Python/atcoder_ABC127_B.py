
import sys
from io import StringIO

def main():
    r, d, x = map(int, input().split())
    for _ in range(10):
        x = r * x - d
        print(x)

if __name__ == "__main__":
    main()


##End of Code
