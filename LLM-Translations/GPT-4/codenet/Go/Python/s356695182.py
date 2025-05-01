import sys
from typing import List
import math

def read_int() -> int:
    return int(input().strip())

def read_ints() -> List[int]:
    return list(map(int, input().strip().split()))

def pattern1(l: List[int]) -> int:
    return (l[0] * l[3]) + (l[1] * l[4])

def pattern2(l: List[int]) -> int:
    return 2 * l[2] * max(l[3], l[4])

def pattern3(l: List[int]) -> int:
    return 2 * l[2] * min(l[3], l[4]) + doch(l)

def min_element(nums: List[int]) -> int:
    return min(nums)

def max_element(nums: List[int]) -> int:
    return max(nums)

def doch(l: List[int]) -> int:
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])
    else:
        return l[1] * (l[4] - l[3])

def main() -> None:
    l = read_ints()
    print(min_element([pattern1(l), pattern2(l), pattern3(l)]))

if __name__ == '__main__':
    main()


