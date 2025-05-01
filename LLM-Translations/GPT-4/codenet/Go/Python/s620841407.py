import sys
from collections import defaultdict


def reroot(node, parent, tree, identity, operate, operate_node):
    dp = defaultdict(int)
    for child in tree[node]:
        if child == parent:
            continue
        dp[node] += reroot(child, node, tree, identity, operate, operate_node)
    return operate_node(dp[node] + identity, node)


def main():
    n, m = map(int, sys.stdin.readline().split())
    tree = defaultdict(list)
    for _ in range(n - 1):
        x, y = map(int, sys.stdin.readline().split())
        x -= 1
        y -= 1
        tree[x].append(y)
        tree[y].append(x)

    identity = 1
    operate = lambda x, y: (x * y) % m
    operate_node = lambda v, p: v + 1

    for i in range(n):
        result = reroot(i, -1, tree, identity, operate, operate_node)
        print(result - 1)

if __name__ == "__main__":
    main()


