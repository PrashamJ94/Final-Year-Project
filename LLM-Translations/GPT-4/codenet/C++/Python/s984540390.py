
import sys
from math import log2, ceil

def main():
    h = int(input().strip())
    ans, cnt = 0, 1

    while h != 1:
        if h % 2 != 0:
            h -= 1
        h //= 2
        cnt *= 2
        ans += cnt

    print(ans + 1)

if __name__ == "__main__":
    main()

#
