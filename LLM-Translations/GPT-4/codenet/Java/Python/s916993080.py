import sys
from io import StringIO
import atexit

def main():
    n = int(input().strip())
    arr = [list(map(int, input().strip().split())) for _ in range(n)]
    dp = [[0] * 3 for _ in range(n)]
    dp[0] = arr[0]
    
    for i in range(1, n):
        for j in range(3):
            if j == 0:
                dp[i][j] = max(arr[i][0] + dp[i-1][1], arr[i][0] + dp[i-1][2])
            if j == 1:
                dp[i][j] = max(arr[i][1] + dp[i-1][0], arr[i][1] + dp[i-1][2])
            if j == 2:
                dp[i][j] = max(arr[i][2] + dp[i-1][1], arr[i][2] + dp[i-1][0])
    
    max_value = max(dp[n-1])
    print(max_value)

if __name__ == '__main__':
    main()


