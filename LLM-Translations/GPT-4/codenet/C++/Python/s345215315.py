import sys
from functools import reduce

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def dfs(x, y, cnt):
    if cnt > 20:
        return
    if x == h - 1:
        ans[0] = min(ans[0], cnt)
        return

    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue
        if s[nx][ny] != 'X':
            continue

        c = True
        while c and s[nx][ny] == 'X':
            s[nx][ny] = '.'
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans[0] = min(ans[0], cnt + 1)
                c = False

        if c:
            dfs(nx, ny, cnt + 1)

        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx][ny] = 'X'

        s[x][y] = '.'

h = 19
w = 15
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

s = []
for _ in range(h):
    s.append(input().strip())

sx, sy = 0, 0
for i in range(h):
    for j in range(w):
        if s[i][j] == 'O':
            sx, sy = i, j
            s[i][j] = '.'

ans = [sys.maxsize]
dfs(sx, sy, 0)

if ans[0] == sys.maxsize:
    print(-1)
else:
    print(ans[0])


