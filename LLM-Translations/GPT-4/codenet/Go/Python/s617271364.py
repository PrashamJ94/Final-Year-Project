import sys
from queue import PriorityQueue
from functools import reduce
import heapq

def dfs(dp, times, arr, N, A, B, C):
    if times >= N:
        ans = calc(dp, arr, A, B, C)
        return ans
    else:
        min_cost = sys.maxsize
        for i in range(4):
            dp[times] = i
            cost = dfs(dp, times + 1, arr, N, A, B, C)
            min_cost = min(min_cost, cost)
        return min_cost

def calc(dp, arr, A, B, C):
    cost = 0
    AA, BB, CC = 0, 0, 0
    memo = [0] * 4
    for i in range(len(dp)):
        memo[dp[i]] += 1
        if dp[i] == 1:
            AA += arr[i]
        elif dp[i] == 2:
            BB += arr[i]
        elif dp[i] == 3:
            CC += arr[i]
    cost += abs(A-AA) + abs(B-BB) + abs(C-CC)

    for i in range(1, 4):
        a = memo[i]
        if a < 1:
            cost += 10000
        else:
            cost += (a - 1) * 10

    return cost

def main():
    X = list(map(int, input().split()))
    N, A, B, C = X[0], X[1], X[2], X[3]
    arr = [int(input()) for _ in range(N)]
    dp = [0] * N
    ans = dfs(dp, 0, arr, N, A, B, C)
    print(ans)

if __name__ == "__main__":
    main()


