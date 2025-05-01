import sys
from typing import List

def min(arr: List[int], n: int) -> int:
    if n == 1:
        return 0
    if n == 2:
        return abs(arr[n - 1] - arr[n - 2])
    op1 = abs(arr[n - 1] - arr[n - 2]) + min(arr, n - 1)
    op2 = abs(arr[n - 1] - arr[n - 3]) + min(arr, n - 2)
    return min(op1, op2)

def dpc(arr: List[List[int]], i: int, n: int, row: int) -> int:
    if row == n:
        return 0
    j, k = 0, 0
    if i == 1:
        j, k = 0, 2
    elif i == 0:
        j, k = 1, 2
    else:
        j, k = 0, 1

    return arr[row][i] + max(dpc(arr, j, n, row + 1), dpc(arr, k, n, row + 1))

def dpx(arr: List[List[int]], n: int) -> int:
    dp = [[0] * 3 for _ in range(n)]

    for i in range(3):
        dp[0][i] = arr[0][i]

    for i in range(1, n):
        for in_ in range(3):
            if in_ == 1:
                j, k = 0, 2
            elif in_ == 0:
                j, k = 1, 2
            else:
                j, k = 0, 1
            dp[i][in_] = max(dp[i - 1][k], dp[i - 1][j]) + arr[i][in_]

    return max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2])

def main():
    n = int(input().strip())
    arr = [list(map(int, input().strip().split())) for _ in range(n)]

    ans = dpx(arr, n)
    print(ans)

if __name__ == "__main__":
    main()


