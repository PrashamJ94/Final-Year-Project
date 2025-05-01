import sys
from typing import List

def main():
    n = int(input().strip())
    arrA = list(map(int, input().strip().split()))

    cumSumA = [0] * (n + 1)
    cumSumA[0] = 0
    for i, a in enumerate(arrA):
        cumSumA[i + 1] = cumSumA[i] + a

    ans = float('inf')
    for i in range(1, n):
        ans = min(ans, abs((cumSumA[n] - cumSumA[i] * 2)))

    print(int(ans))

if __name__ == "__main__":
    main()


