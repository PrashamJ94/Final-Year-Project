import sys
from collections import deque

MOD = 1000000007

def main():
    cs = input().strip()
    dp = [ [0] * 13 for _ in range(len(cs)) ]
    base = 1
    for i in range(len(cs)):
        if cs[len(cs) - 1 - i] == '?':
            for pre in range(13):
                for next in range(10):
                    dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (1 if pre == 0 else 0))
                    dp[i][(base * next + pre) % 13] %= MOD
        else:
            next = int(cs[len(cs) - 1 - i]) - int('0')
            for pre in range(13):
                dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (1 if pre == 0 else 0))
                dp[i][(base * next + pre) % 13] %= MOD
        base = (base * 10) % 13
    print(dp[len(dp) - 1][5])

if __name__ == "__main__":
    main()


