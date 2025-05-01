import sys
from typing import List, Set, Tuple, Optional

class Main:
    def __init__(self):
        self.H, self.W = map(int, input().split())
        self.c = [list(map(int, input().split())) for _ in range(10)]
        self.A = [list(map(int, input().split())) for _ in range(self.H)]

    def solve(self):
        min_cost = [0] * 10

        for i in range(10):
            min_cost[i] = self.c[i][1]

        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], self.c[i][j] + min_cost[j])

        ans = 0
        for h in range(self.H):
            for w in range(self.W):
                if self.A[h][w] >= 0:
                    ans += min_cost[self.A[h][w]]
        print(ans)

if __name__ == '__main__':
    main = Main()
    main.solve()


