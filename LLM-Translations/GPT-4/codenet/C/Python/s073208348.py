
from sys import stdin

def esort(edge):
    return (edge[0], edge[1])

def readgraph():
    n = int(input())
    edges = []
    for _ in range(n-1):
        x, y, c = map(int, input().split())
        edges.append((x, y, c))
        edges.append((y, x, c))
    
    edges.sort(key=esort)
    
    graph = [[] for _ in range(n)]
    for edge in edges:
        graph[edge[0]].append((edge[1], edge[2]))
    
    return graph

def tyokkeidfs(graph, s, temp):
    for edge in graph[s]:
        if temp[edge[0]] == 0:
            temp[edge[0]] = temp[s] + edge[1]
            tyokkeidfs(graph, edge[0], temp)

def tyokkei(graph):
    temp = [0] * (len(graph) + 10)
    temp[0] = 1
    tyokkeidfs(graph, 0, temp)
    M, Mi = 0, 0
    for i, val in enumerate(temp):
        if val > M:
            M, Mi = val, i
    for i in range(len(graph)):
        temp[i] = 0
    temp[Mi] = 1
    tyokkeidfs(graph, Mi, temp)
    return max(temp) - 1

def main():
    graph = readgraph()
    print(tyokkei(graph))

main()


