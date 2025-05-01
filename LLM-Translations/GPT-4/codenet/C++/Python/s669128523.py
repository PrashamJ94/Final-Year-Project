
def dfs_visit(u):
    global tt
    v = 0
    color[u] = GRAY
    d[u] = tt = tt + 1
    for v in range(n):
        if M[u][v] == 0:
            continue
        if color[v] == WHITE:
            dfs_visit(v)
    color[u] = BLACK
    f[u] = tt = tt + 1

def dfs():
    global tt
    for i in range(n):
        color[i] = WHITE
    tt = 0

    for u in range(n):
        if color[u] == WHITE:
            dfs_visit(u)

    for i in range(n):
        print(i + 1, d[i], f[i])

if __name__ == "__main__":
    N = 100
    WHITE = 0
    GRAY = 1
    BLACK = 2

    M = [[0] * N for _ in range(N)]
    n = int(input())
    color = [0] * n
    d = [0] * n
    f = [0] * n
    tt = 0

    for _ in range(n):
        u, k, *vertices = map(int, input().split())
        u -= 1
        for v in vertices:
            v -= 1
            M[u][v] = 1

    dfs()


