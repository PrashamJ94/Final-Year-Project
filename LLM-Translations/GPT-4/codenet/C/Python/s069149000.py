import sys

INF = 100000
MAX = 101
NIL = -6
WHITE = 0
GRAY = 1
BLACK = 2

def prim(n, G):
    d = [INF for _ in range(n)]
    pi = [NIL for _ in range(n)]
    color = [WHITE for _ in range(n)]
    sum = 0

    d[0] = 0

    while True:
        min_val = INF
        u = NIL
        for i in range(n):
            if color[i] != BLACK and d[i] < min_val:
                min_val = d[i]
                u = i

        if u == NIL:
            break

        color[u] = BLACK

        for v in range(n):
            if color[v] != BLACK and G[u][v] != INF:
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY

    for i in range(n):
        if pi[i] != NIL:
            sum += G[i][pi[i]]

    return sum

def main():
    n = int(input())
    G = []

    for i in range(n):
        row = list(map(int, input().split()))
        G.append([INF if e == -1 else e for e in row])

    result = prim(n, G)
    print(result)

if __name__ == "__main__":
    main()


