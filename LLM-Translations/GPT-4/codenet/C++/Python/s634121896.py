
from sys import stdin
from collections import defaultdict

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    dp = [0] * (n+1)
    dp[0] = 1
    kek = defaultdict(int)
    prev = defaultdict(int)
    
    for i in range(1, n+1):
        dp[i] = dp[i-1] + (prev[nums[i-1]] != i-1) * kek[nums[i-1]]
        dp[i] %= 1000000007
        kek[nums[i-1]] = dp[i]
        prev[nums[i-1]] = i
        
    print(dp[n])


if __name__ == "__main__":
    main()


