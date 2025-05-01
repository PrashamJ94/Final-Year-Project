
from sys import stdin
from typing import List

def main():
    n, *ar = map(int, stdin.read().split())
    ar.sort()
    sum_ = sum(ar[3 * n - (i + 1) * 2] for i in range(n))
    print(sum_)

if __name__ == "__main__":
    main()


