import sys
from typing import List

def main(N: int, D: int, X: int, A: List[int]) -> int:
    num_of_chocolate = 0
    for i in range(N):
        days = 0
        counter = 0
        for j in range(sys.maxsize):
            days = j * A[i] + 1
            if days <= D:
                counter += 1
            else:
                break
        num_of_chocolate += counter
    num_of_chocolate += X

    return num_of_chocolate

if __name__ == "__main__":
    N, D, X = map(int, input().split())
    A = [int(input()) for _ in range(N)]
    result = main(N, D, X, A)
    print(result)


