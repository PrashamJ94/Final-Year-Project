
import sys
from typing import List, Tuple

def main() -> None:
    N, _ = map(int, input().split())
    A = list(map(int, input().split()))
    max_profit = 0
    max_cnt = 0
    max_a = A[N - 1]
    for i in range(N - 2, -1, -1):
        profit = max(0, max_a - A[i])
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        max_a = max(max_a, A[i])
    print(max_cnt)

if __name__ == "__main__":
    main()

#
