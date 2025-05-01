
from itertools import combinations
from typing import List

def main() -> None:
    N = int(input())
    A = list(map(int, input().split()))

    answer = 0
    for i, j in combinations(range(N), 2):
        diff = abs(A[i] - A[j])
        answer = max(answer, diff)

    print(answer)

if __name__ == "__main__":
    main()


