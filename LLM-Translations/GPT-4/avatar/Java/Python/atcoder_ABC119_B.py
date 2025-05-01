import sys
from typing import List, Tuple

def main() -> None:
    N = int(input().strip())
    x_u = [tuple(input().strip().split()) for _ in range(N)]
    print(solve(x_u))

def solve(x_u: List[Tuple[str, str]]) -> float:
    return sum(float(x) * (1 if u == "JPY" else 380000) for x, u in x_u)

if __name__ == '__main__':
    main()


