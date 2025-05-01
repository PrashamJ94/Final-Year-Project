
import sys
from math import max

def main():
    N, M = map(int, input().split())
    values = [0] * N
    weights = [0] * N
    for i in range(N):
        weights[i], values[i] = map(int, input().split())
    
    dp = [[0] * (M+1) for _ in range(N+1)]
    
    for i in range(1, N+1):
        for j in range(M+1):
            dp[i][j] = dp[i-1][j]
            if j >= weights[i-1]:
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]] + values[i-1])
    
    print(dp[N][M])

if __name__ == "__main__":
    main()


