
import sys
import math
from typing import List, Tuple

def solve(a: int, b: int) -> None:
    print(max(0, a-2*b))

def main() -> None:
    a, b = map(int, input().split())
    solve(a, b)

if __name__ == '__main__':
    main()


