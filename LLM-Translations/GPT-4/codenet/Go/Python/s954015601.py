
from collections import defaultdict

def genid(a, b):
    if b < a:
        a, b = b, a
    return a*100000 + b

def dfs(edges, colors, current_node, used_color, parent_node):
    color = 1
    for child_node in edges[current_node]:
        if child_node == parent_node:
            continue
        if color == used_color:
            color += 1
        colors[genid(current_node, child_node)] = color
        dfs(edges, colors, child_node, color, current_node)
        color += 1

def main():
    N = int(input())
    ab = [tuple(map(int, input().split())) for _ in range(N - 1)]

    edges = defaultdict(list)
    for a, b in ab:
        a, b = a - 1, b - 1
        edges[a].append(b)
        edges[b].append(a)

    colors = {}
    dfs(edges, colors, 0, -1, -1)

    K = max(len(edges[i]) for i in range(N))
    print(K)

    for a, b in ab:
        print(colors[genid(a - 1, b - 1)])

if __name__ == "__main__":
    main()


