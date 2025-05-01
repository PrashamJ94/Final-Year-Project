import sys
from functools import lru_cache

def main():
    n, a, b, c = map(int, input().split())
    arr = [a, b, c]
    maxn = 4010

    @lru_cache(maxsize=None)
    def dp(j):
        if j == 0:
            return 0
        if j < 0:
            return -sys.maxsize
        return max(dp(j - arr[i]) + 1 for i in range(3))

    print(dp(n))

if __name__ == "__main__":
    main()


