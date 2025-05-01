Here is the Python translation of your Java code:


from collections import defaultdict

n = int(input())
g = defaultdict(list)
ans = [0]*(n-1)
edges = []

for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append((i, b))
    g[b].append((i, a))
    edges.append((a, b))

def dfs(to, color, parents):
    k = 1
    for e in g[to]:
        if e[1] == parents:
            continue
        if k == color:
            k += 1
        ans[e[0]] = k
        dfs(e[1], k, to)
        k += 1

dfs(0, -1, -1)

print(max(ans))
for a, b in edges:
    print(ans[a, b])


