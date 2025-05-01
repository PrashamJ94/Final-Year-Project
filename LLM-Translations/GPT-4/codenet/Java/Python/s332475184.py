import sys
from collections import defaultdict

def dfs(v, par, val):
    global counter, graph
    for i in graph[v]:
        if i != par:
            dfs(i, v, val + counter[v])
    counter[v] += val

def main():
    global counter, graph
    n, q = map(int, sys.stdin.readline().split())
    graph = defaultdict(list)

    for _ in range(n - 1):
        a, b = map(int, sys.stdin.readline().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    counter = [0] * n
    for _ in range(q):
        p, x = map(int, sys.stdin.readline().split())
        counter[p - 1] += x

    dfs(0, -1, 0)
    print(' '.join(map(str, counter)))

main()


