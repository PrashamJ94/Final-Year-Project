import sys
from typing import List, Tuple

def main():
    A, B, C = map(int, sys.stdin.readline().split())
    if B - A == C - B:
        print("YES")
    else:
        print("NO")

# Helper functions
def int_max(a: int, b: int) -> int:
    return max(a, b)

def int64_max(a: int, b: int) -> int:
    return max(a, b)

def float64_max(a: float, b: float) -> float:
    return max(a, b)

def int_min(a: int, b: int) -> int:
    return min(a, b)

def int64_min(a: int, b: int) -> int:
    return min(a, b)

def float64_min(a: float, b: float) -> float:
    return min(a, b)

def int_gcd(a: int, b: int) -> int:
    return gcd(a, b)

def int64_gcd(a: int, b: int) -> int:
    return gcd(a, b)

def int_abs(a: int) -> int:
    return abs(a)

def int64_abs(a: int) -> int:
    return abs(a)

if __name__ == "__main__":
    main()


