
from sys import stdin

def main():
    N, W = map(int, input().split())
    items = [tuple(map(int, input().split())) for _ in range(N)]

    dp = [[0] * (W + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        v, w = items[i - 1]
        for j in range(W + 1):
            if j < w:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)

    print(dp[N][W])

if __name__ == '__main__':
    main()


