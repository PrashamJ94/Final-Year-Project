
import sys
from itertools import combinations

def main():
    _ = input()
    data = list(map(int, input().split()))

    sum_pairs = sum(x * y for x, y in combinations(data, 2))

    print(sum_pairs)

if __name__ == "__main__":
    main()


