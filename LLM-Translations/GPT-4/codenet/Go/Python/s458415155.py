import sys
from typing import List, Tuple

def iabs(x: int) -> int:
    return abs(x)

def solve(n: int, heights: List[int]) -> int:
    t = [float('inf')] * (n + 1)

    t[0] = 0
    for i in range(1, n):
        if (v := t[i - 1] + iabs(heights[i] - heights[i - 1])) < t[i]:
            t[i] = v
        if 1 < i:
            if (v := t[i - 2] + iabs(heights[i] - heights[i - 2])) < t[i]:
                t[i] = v

    return t[n - 1]

def main() -> None:
    n = int(input().strip())
    heights = list(map(int, input().split()))
    ans = solve(n, heights)
    print(ans)

if __name__ == "__main__":
    main()


