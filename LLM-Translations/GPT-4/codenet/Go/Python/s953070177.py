import sys
from typing import List, Tuple

def get_next_int(lines: List[str]) -> Tuple[int, List[str]]:
    return int(lines.pop(0)), lines

def absint(a: int) -> int:
    return abs(a)

def main() -> None:
    lines = sys.stdin.readlines()
    n, lines = get_next_int(lines)

    aa = [0] * (n+2)
    sum = 0

    for i in range(n):
        aa[i+1], lines = get_next_int(lines)
        sum += absint(aa[i+1] - aa[i])

    sum += absint(aa[n+1] - aa[n])

    for i in range(1, n+1):
        ans = sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1])
        print(ans)

if __name__ == "__main__":
    main()


