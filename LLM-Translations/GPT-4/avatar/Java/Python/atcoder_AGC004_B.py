import sys
from typing import List

def main() -> None:
    N, x = map(int, input().split())
    srimeList = list(map(int, input().split()))

    costList = [[0] * N for _ in range(N)]

    for i in range(N):
        costList[i][0] = srimeList[i]
        for castNum in range(1, N):
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N])

    result = []

    for i in range(N):
        result.append(i * x + sum(costList[j][i] for j in range(N)))

    print(min(result))

if __name__ == '__main__':
    main()


