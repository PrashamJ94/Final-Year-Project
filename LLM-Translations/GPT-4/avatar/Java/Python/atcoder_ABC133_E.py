import sys
from collections import deque

def main():
    N, K = map(int, input().split())
    edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(N - 1)]

    nodes = [set() for _ in range(N)]
    for a, b in edges:
        nodes[a].add(b)
        nodes[b].add(a)

    mod = 1_000_000_007
    patterns = [0] * N
    patterns[0] = K

    q = deque([(0, -1, K)])
    while q:
        node, parent, use = q.popleft()
        count = 1
        if parent != -1:
            count += 1

        for child in nodes[node]:
            if child == parent:
                continue

            patterns[child] = (K - count)
            count += 1
            q.append((child, node, patterns[child]))

    result = 1
    for p in patterns:
        result = (result * p) % mod

    print(result)

main()


