import sys
from fractions import gcd
from functools import reduce
from itertools import groupby

def main():
    N = int(input())
    balls = sorted([tuple(map(int, input().split())) for _ in range(N)])
    ans = N

    def solve():
        nonlocal ans
        for add in range(1, N):
            taken = [False] * N
            p = balls[add][0] - balls[0][0]
            q = balls[add][1] - balls[0][1]
            ans = min(ans, check(p, q, balls, taken))

    def check(p, q, balls, taken):
        ret = 0
        while True:
            added = False
            start = 0
            x = -1
            y = -1
            for i in range(N):
                if not taken[i]:
                    added = True
                    ret += 1
                    start = i
                    taken[i] = True
                    x = balls[i][0] + p
                    y = balls[i][1] + q
                    break
            if not added:
                break
            for i in range(start + 1, N):
                if balls[i][0] == x and balls[i][1] == y:
                    taken[i] = True
                    x += p
                    y += q
        return ret

    solve()
    balls = sorted([(y, x) for x, y in balls])
    solve()
    print(ans)

main()


