
import sys
def main():
    N, M = map(int, input().split())
    Inf = 1 << 62
    edges = []
    for _ in range(M):
        a, b, c = map(int, input().split())
        edges.append((a - 1, b - 1, -c))
    dist = [Inf] * N
    dist[0] = 0
    for _ in range(N):
        for a, b, c in edges:
            if dist[a] == Inf:
                continue
            if dist[b] > dist[a] + c:
                dist[b] = dist[a] + c
    ans = dist[N - 1]
    navigate = [False] * N
    for _ in range(N):
        for a, b, c in edges:
            if dist[a] == Inf:
                continue
            if dist[b] > dist[a] + c:
                dist[b] = dist[a] + c
                navigate[b] = True
            if navigate[a]:
                navigate[b] = True
    if navigate[N - 1]:
        print("inf")
    else:
        print(-ans)

if __name__ == "__main__":
    main()


#
