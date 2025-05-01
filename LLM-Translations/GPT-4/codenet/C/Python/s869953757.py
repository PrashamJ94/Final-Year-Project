import sys
from collections import deque

M = 100
whi = 0
gra = 1
bla = 2

def bfs(s, n, T):
    color = [whi] * n
    d = [1000000] * n
    Q = deque()

    color[s] = gra
    d[s] = 0
    Q.append(s)

    while Q:
        u = Q.popleft()
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra
                d[v] = d[u] + 1
                Q.append(v)
        color[u] = bla

    return d

def main():
    n = int(input().strip())
    T = [[0] * n for _ in range(n)]

    for _ in range(n):
        data = list(map(int, input().split()))
        u, k = data[0] - 1, data[1]
        for v in data[2:]:
            T[u][v - 1] = 1

    d = bfs(0, n, T)

    for i in range(n):
        if d[i] == 1000000:
            d[i] = -1
        print(i + 1, d[i])

if __name__ == "__main__":
    main()


