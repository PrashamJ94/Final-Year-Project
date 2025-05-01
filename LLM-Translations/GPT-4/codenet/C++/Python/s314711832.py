import sys
from heapq import heappush, heappop

INF = 1000000001
N = 100000

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def main():
    input = sys.stdin.readline
    
    V, E, r = map(int, input().split())
    edges = [[] for _ in range(V)]

    for i in range(E):
        source, target, distance = map(int, input().split())
        new_edge = Edge(source, target, distance)
        edges[source].append(new_edge)

    distances = [INF] * N
    distances[r] = 0
    q = [(0, r)]

    while q:
        distance, node = heappop(q)
        if distances[node] < distance:
            continue
        for edge in edges[node]:
            new_distance = distance + edge.weight
            if distances[edge.target] > new_distance:
                distances[edge.target] = new_distance
                heappush(q, (new_distance, edge.target))

    for i in range(V):
        if distances[i] == INF:
            print("INF")
        else:
            print(distances[i])

if __name__ == "__main__":
    main()


