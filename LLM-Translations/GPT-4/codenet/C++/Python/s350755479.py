import sys
from typing import List, Tuple

class Node:
    def __init__(self, x: int, y: int, id: int):
        self.x = x
        self.y = y
        self.id = id

class Edge:
    def __init__(self, u: int, v: int, val: int):
        self.u = u
        self.v = v
        self.val = val

    def __lt__(self, other):
        return self.val < other.val

def findpar(x: int, par: List[int]) -> int:
    if par[x] == x:
        return x
    par[x] = findpar(par[x], par)
    return par[x]

def unite(x: int, y: int, par: List[int]) -> None:
    x = findpar(x, par)
    y = findpar(y, par)
    if x == y:
        return
    par[x] = y

def minimum_spanning_tree(n: int, nodes: List[Tuple[int, int]]) -> int:
    par = [i for i in range(n + 1)]

    node = [Node(0, 0, 0)] + [Node(x, y, i) for i, (x, y) in enumerate(nodes, start=1)]

    node.sort(key=lambda n: n.x)
    cnt = 0
    e = []
    for i in range(2, n + 1):
        e.append(Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x))
        cnt += 1

    node.sort(key=lambda n: n.y)
    for i in range(2, n + 1):
        e.append(Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y))
        cnt += 1

    e.sort()

    ans = 0
    for i in range(cnt):
        u, v, val = e[i].u, e[i].v, e[i].val
        if findpar(u, par) == findpar(v, par):
            continue
        unite(u, v, par)
        ans += val

    return ans

def main() -> None:
    n = int(input().strip())
    nodes = [tuple(map(int, input().split())) for _ in range(n)]
    ans = minimum_spanning_tree(n, nodes)
    print(ans)

if __name__ == "__main__":
    main()


