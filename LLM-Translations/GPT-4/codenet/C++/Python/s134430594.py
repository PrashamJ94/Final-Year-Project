
from sys import stdin
from math import log2

def sparse_table_init(a):
    n = len(a)
    LIM = 20
    N = 2 * 10**5 + 7
    mn = [[0] * N for _ in range(LIM)]
    pw = [0] * N

    for i in range(n):
        mn[0][i] = a[i]

    for i in range(LIM - 1):
        for j in range(n - (1 << (i + 1)) + 1):
            mn[i + 1][j] = max(mn[i][j], mn[i][j + (1 << i)])

    pw[1] = 0
    for i in range(2, N):
        pw[i] = pw[i // 2] + 1

    return mn, pw

def sparse_table_get(l, r, mn, pw):
    r += 1
    p = pw[r - l]
    return min(mn[p][l], mn[p][r - (1 << p)])

def main():
    n = int(input())
    a = list(map(int, input().split()))
    dl = [0] * n

    for i in range(n):
        if a[i] > i:
            print(-1)
            return

        dl[i] = i - a[i]

    ans = 0
    bans = []
    i = 0
    while i < n:
        r = i
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1

        ans += a[r]
        i = r
        bans.append((r - a[r], r, r - a[r]))
        i += 1

    mn, pw = sparse_table_init(dl)
    for t in bans:
        if sparse_table_get(t[0], t[1], mn, pw) > t[2]:
            print(-1)
            return

    print(ans)

if __name__ == "__main__":
    main()


#
