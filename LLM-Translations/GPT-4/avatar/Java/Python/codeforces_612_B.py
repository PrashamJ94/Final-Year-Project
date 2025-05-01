import sys

def main():
    n = int(input())
    dp = [0] * (200001)
    nums = list(map(int, input().split()))

    for i in range(n):
        dp[nums[i]] = i

    ans = 0
    for i in range(2, n + 1):
        ans += abs(dp[i] - dp[i - 1])

    print(ans)

if __name__ == "__main__":
    main()


