import sys
from typing import List, Tuple

def next_int() -> int:
    return int(input().strip())

def next_float() -> float:
    return float(input().strip())

def next_ints(n: int) -> List[int]:
    return [int(x) for x in input().strip().split()[:n]]

def main() -> None:
    n, k = map(int, input().strip().split())
    a = next_ints(n)
    # 変数未使用エラー回避
    a[0] = 0

    sum = k
    ans = 1
    while sum < n:
        sum = sum - 1 + k
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()


