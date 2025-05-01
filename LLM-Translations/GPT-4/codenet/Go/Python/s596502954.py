import sys
from typing import List, Tuple

def input() -> str:
    return sys.stdin.readline().strip()

def next_int() -> int:
    return int(input())

def next_float() -> float:
    return float(input())

def next_ints(n: int) -> List[int]:
    return [next_int() for _ in range(n)]

def main() -> None:
    if next_int() + next_int() >= next_int():
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


