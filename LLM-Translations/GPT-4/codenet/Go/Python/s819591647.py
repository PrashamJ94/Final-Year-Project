
import sys
from typing import List, Tuple

def getInt() -> int:
    return int(input())

def getIntSlice(n: int) -> List[int]:
    return list(map(int, input().split()))

def solve() -> None:
    n, m = map(int, input().split())
    a = getIntSlice(n)

    sum_a = sum(a)

    count = 0
    for v in a:
        rate = sum_a / (4 * m)
        if v >= rate:
            count += 1

    if count >= m:
        print("Yes")
    else:
        print("No")

def main() -> None:
    solve()

if __name__ == '__main__':
    main()

#
