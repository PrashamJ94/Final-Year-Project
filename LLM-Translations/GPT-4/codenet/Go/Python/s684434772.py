import sys
from typing import List, Tuple

def main():
    n, k = map(int, input().split())

    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total = total % (pow(10, 9) + 7)
    print(total)

def combi(n: int, k: int) -> int:
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    return max_val - min_val + 1

if __name__ == "__main__":
    main()


