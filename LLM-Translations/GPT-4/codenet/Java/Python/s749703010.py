import sys
from collections import defaultdict
from functools import lru_cache

def main():
    n = int(input().strip())
    a = [list(map(int, input().strip().split())) for _ in range(2)]

    @lru_cache(None)
    def dp(fliped, idx, msk):
        if msk == (1 << n) - 1:
            return 0
        if idx == n:
            return float('inf')
        x = bin(msk).count('1')
        ff = 0
        ans = float('inf')
        for i in range(n):
            if not (msk & (1 << i)):
                nf = x % 2
                if a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]:
                    ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i))
                ff += 1
            else:
                x -= 1
        return ans

    ans = dp(0, n, 0)
    print(ans if ans < float('inf') else -1)

main()

