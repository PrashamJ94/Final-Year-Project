Sure, Here is your translated Python code:


from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices
        self.color_arr = [-1] * self.V

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs(self, v, c):
        self.color_arr[v] = c
        total = 1

        for i in self.graph[v]:
            if self.color_arr[i] == -1:
                total += self.dfs(i, 1 - c)
            elif self.color_arr[i] == c:
                return 0
        return total

def main():
    n, m = map(int, input().strip().split())
    g = Graph(n)

    for _ in range(m):
        u, v = map(int, input().strip().split())
        g.addEdge(u-1, v-1)

    one = bipartite = count = 0
    for i in range(n):
        if g.color_arr[i] == -1:
            count += 1
            kind = g.dfs(i, 1)
            if kind == 1:
                one += 1
            elif kind > 1:
                bipartite += 1

    total = one * (2 * n - one)
    total += (count - one) * (count - one)
    total += bipartite * bipartite

    print(total)

if __name__ == "__main__":
    main()


