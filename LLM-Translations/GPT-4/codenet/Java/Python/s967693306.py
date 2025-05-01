import sys
from typing import List, Tuple

INF = sys.maxsize // 2
MOD = 1_000_000_007
SIZE = 1_000_000


class Main:
    def __init__(self):
        self.fac = [0] * SIZE
        self.inv = [0] * SIZE
        self.finv = [0] * SIZE

    def solve(self):
        n, m = map(int, input().split())
        smap = {}
        for _ in range(m):
            s, c = map(int, input().split())
            if s in smap and smap[s] != c:
                print(-1)
                sys.exit(0)
            smap[s] = c

        for i in range(1000):
            s = str(i)
            if len(s) < n:
                continue

            flag = True
            for j in range(n):
                if (j + 1 in smap and smap[j + 1] != int(s[j])) or (j + 1 not in smap and int(s[j]) != 0):
                    if j == 0 and int(s[j]) == 1:
                        continue
                    flag = False
                    break

            if flag and len(s) == n:
                print(s)
                sys.exit(0)

        print(-1)


if __name__ == "__main__":
    main = Main()
    main.solve()


