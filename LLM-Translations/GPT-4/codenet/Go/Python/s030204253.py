import sys
from typing import List

def merge_average(numbers: List[float]) -> float:
    if len(numbers) == 1:
        return numbers[0]

    numbers.sort()
    merged = (numbers[0] + numbers[1]) / 2
    new_numbers = numbers[2:]
    new_numbers.append(merged)

    return merge_average(new_numbers)

def main():
    n = int(input())
    a = list(map(float, input().split()))

    result = merge_average(a)

    print(result)

if __name__ == "__main__":
    main()


