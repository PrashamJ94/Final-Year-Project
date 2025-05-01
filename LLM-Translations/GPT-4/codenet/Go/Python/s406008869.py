import sys
from typing import List

def print_edge(e: List[List[int]], n: int):
    for i in range(1, n+1):
        print(f"{i}: ", end="")
        for v in e[i]:
            print(f"{v} ", end="")
        print()

def dfs(v: int, visited: List[bool], n: int, e: List[List[int]]) -> int:
    comp = True
    for i in range(1, n+1):
        if not visited[i]:
            comp = False

    if comp:
        return 1

    count = 0
    for ne in e[v]:
        if visited[ne]:
            continue
        visited[ne] = True
        rst = dfs(ne, visited, n, e)
        count += rst
        visited[ne] = False
    return count

def main():
    n, m = map(int, input().split())

    e = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)

    visited = [False] * (n+1)
    visited[1] = True
    count = dfs(1, visited, n, e)
    print(count)

if __name__ == "__main__":
    main()


