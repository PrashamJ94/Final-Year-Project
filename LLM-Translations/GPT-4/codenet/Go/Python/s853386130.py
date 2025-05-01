import sys
from itertools import permutations
from heapq import heapify, heappush, heappop

INF = 1000000007

def main():
    n, m, R = map(int, sys.stdin.readline().split())
    rs = list(map(int, sys.stdin.readline().split()))
    rs = [r - 1 for r in rs]

    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        a -= 1
        b -= 1
        costs[a][b] = c
        costs[b][a] = c

    # Floyd-Warshall algorithm for shortest paths
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # Try all permutations of visiting order
    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j - 1]
            to = perm[j]
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

if __name__ == "__main__":
    main()


