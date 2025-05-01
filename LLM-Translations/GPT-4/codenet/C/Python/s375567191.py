def visit(u, g, color, d, f, time):
    color[u] = "GRAY"
    time[0] += 1
    d[u] = time[0]

    for i in range(len(g[u])):
        if g[u][i] == 0:
            continue
        if color[i] == "WHITE":
            visit(i, g, color, d, f, time)

    color[u] = "BLACK"
    time[0] += 1
    f[u] = time[0]

def dfs(g, n):
    time = [0]
    d = [0] * n
    f = [0] * n
    color = ["WHITE"] * n

    for i in range(n):
        if color[i] == "WHITE":
            visit(i, g, color, d, f, time)

    for i in range(n):
        print(i + 1, d[i], f[i])

def main():
    n = int(input())
    g = [[0 for _ in range(MAX)] for _ in range(MAX)]

    for _ in range(n):
        x, y, *edges = [int(e) for e in input().split()]
        for z in edges:
            g[x - 1][z - 1] = 1

    dfs(g, n)

if __name__ == "__main__":
    main()


