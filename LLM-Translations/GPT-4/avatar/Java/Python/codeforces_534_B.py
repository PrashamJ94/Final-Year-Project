import sys
from collections import defaultdict

def main():
    v1, v2, t, d = map(int, input().split())
    dp = defaultdict(lambda: -(10**17))
    dp[v1] = v1
    for i in range(1, t-1):
        new_dp = defaultdict(lambda: -(10**17))
        for j in range(1150):
            for x in range(d+1):
                if j + x < 1150:
                    new_dp[j] = max(new_dp[j], dp[j + x] + j)
            for x in range(d, -1, -1):
                if j - x >= 0:
                    new_dp[j] = max(new_dp[j], dp[j - x] + j)
        dp = new_dp

    ans = -sys.maxsize
    for j in range(1150):
        if abs(j - v2) <= d:
            ans = max(ans, dp[j] + v2)

    print(ans)

if __name__ == "__main__":
    main()


