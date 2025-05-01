import sys
from functools import reduce

def main():
    n, m = map(int, input().split())
    keys = [0] * (m + 1)
    costs = [0] * (m + 1)
    INF = 123456789012
    dp = [[INF] * (m + 1) for _ in range(1 << n)]
    dp[0][0] = 0

    for i in range(1, m + 1):
        cost, b, *c = map(int, input().split())
        costs[i] = cost
        keys[i] = reduce(lambda acc, x: acc | (1 << (x - 1)), c, 0)

    for i in range(1 << n):
        for j in range(m):
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
            dp[i | keys[j + 1]][j + 1] = min(dp[i | keys[j + 1]][j + 1], dp[i][j] + costs[j + 1])

    print(dp[(1 << n) - 1][m] if dp[(1 << n) - 1][m] != INF else -1)

main()

