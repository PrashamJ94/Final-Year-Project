import sys
import os
from typing import Any, Tuple, List

def get_next_string(scanner: List[str]) -> str:
    return scanner.pop(0)

def get_next_int(scanner: List[str]) -> int:
    return int(get_next_string(scanner))

def get_next_int64(scanner: List[str]) -> int:
    return int(get_next_string(scanner))

def get_next_uint64(scanner: List[str]) -> int:
    return int(get_next_string(scanner))

def get_next_float64(scanner: List[str]) -> float:
    return float(get_next_string(scanner))

def solve(scanner: List[str]) -> str:
    k = get_next_int(scanner)
    x = get_next_int(scanner)

    ans = "No"
    if k * 500 >= x:
        ans = "Yes"
    return ans

def main() -> None:
    scanner = sys.stdin.read().split()
    print(solve(scanner))

if __name__ == "__main__":
    main()


