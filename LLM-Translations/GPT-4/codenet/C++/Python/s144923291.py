import math
import sys
from typing import List, Tuple

def main():
    h, w = map(int, input().split())
    ans = 0
    s = "snuke"

    for i in range(h):
        row = input().split()

        for j in range(w):
            if row[j] == s:
                print(chr(ord('A') + j) + str(i + 1))
                sys.exit(0)

if __name__ == "__main__":
    main()


