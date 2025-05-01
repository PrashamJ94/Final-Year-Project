import sys
from typing import List

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    dp = [[[-1.0 for _ in range(n + 1)] for _ in range(n + 1)] for _ in range(n + 1)]
    dp[0][0][0] = 0
    cnt = [0, 0, 0]
    for i in range(n):
        cnt[a[i] - 1] += 1

    print(rec(cnt[0], cnt[1], cnt[2], n, dp))


def rec(i: int, j: int, k: int, n: int, dp: List[List[List[float]]]) -> float:
    if dp[i][j][k] != -1:
        return dp[i][j][k]

    ret = 0.0
    p = (i + j + k) / n
    pi = i / n
    pj = j / n
    pk = k / n
    ret += 1 / p
    if i > 0:
        ret += pi / p * rec(i - 1, j, k, n, dp)
    if j > 0:
        ret += pj / p * rec(i + 1, j - 1, k, n, dp)
    if k > 0:
        ret += pk / p * rec(i, j + 1, k - 1, n, dp)

    dp[i][j][k] = ret
    return ret


if __name__ == "__main__":
    main()


