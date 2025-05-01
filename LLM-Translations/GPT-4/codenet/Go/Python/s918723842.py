import sys
from typing import List, Tuple


def main():
    H, W, N = map(int, input().split())
    A = max(H, W)
    print((N + A - 1) // A)


def max(a: int, b: int) -> int:
    if a < b:
        return b
    return a


if __name__ == '__main__':
    main()


