import sys
from collections import defaultdict

sys.setrecursionlimit(100000)

def dfs(v):
    used[v] = True
    grundy[v] = 0
    for i in G[v]:
        if not used[i]:
            dfs(i)
            grundy[v] ^= (grundy[i] + 1)

N = int(input())
G = defaultdict(list)
used = [False] * 100000
grundy = [0] * 100000

for _ in range(N - 1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

dfs(0)

if grundy[0] != 0:
    print("Alice")
else:
    print("Bob")


