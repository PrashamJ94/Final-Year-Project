import sys
from typing import List, Tuple
from functools import lru_cache

def main():
    while True:
        W, H = map(int, input().split())
        if W == 0 and H == 0:
            break
        map_data = [input().strip() for _ in range(H)]

        dp = [[0] * W for _ in range(H)]

        for h in range(H):
            for w in range(W):
                hprev = 0
                if h >= 1:
                    hprev = dp[h - 1][w]
                wprev = 0
                if w >= 1:
                    wprev = dp[h][w - 1]
                if map_data[h][w].isdigit():
                    max_val = max(hprev, wprev)
                    dp[h][w] = max_val * 10 + int(map_data[h][w])
                else:
                    dp[h][w] = 0

        max_val = 0
        for h in range(H):
            for w in range(W):
                if dp[h][w] > max_val:
                    max_val = dp[h][w]
        print(max_val)

if __name__ == "__main__":
    main()


