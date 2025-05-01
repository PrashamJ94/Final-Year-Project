import sys
sys.setrecursionlimit(1000000)

mod = 1000000007

def dfs(s, dp):
    if dp[s] != -1:
        return dp[s]

    ret = 0
    for i in range(s - 3, -1, -1):
        ret += dfs(i, dp)
        ret %= mod
    dp[s] = ret
    return ret

def main():
    s = int(input().strip())
    dp = [-1] * (s + 1)
    dp[0] = 1

    print(dfs(s, dp))

if __name__ == '__main__':
    main()


