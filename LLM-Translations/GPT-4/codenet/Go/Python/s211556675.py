import sys
from typing import List, Tuple

# I/O
def input_int() -> int:
    return int(input().strip())

def input_float() -> float:
    return float(input().strip())

def input_str() -> str:
    return input().strip()

def input_int_list() -> List[int]:
    return list(map(int, input().strip().split()))

def input_float_list() -> List[float]:
    return list(map(float, input().strip().split()))

def input_tuple() -> Tuple[int, int]:
    return tuple(map(int, input().strip().split()))

# Arithmetic
def max_value(nums: List[int]) -> int:
    return max(nums)

def min_value(nums: List[int]) -> int:
    return min(nums)

def abs_value(x: int) -> int:
    return abs(x)

def pow_value(x: int, y: int) -> int:
    return pow(x, y)

def main():
    A, B, C, K = input_int_list()
    ma = max_value([A, B, C])
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B
    for i in range(1, K + 1):
        ma *= 2

    print(ma + rest)

if __name__ == "__main__":
    main()


