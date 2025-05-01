import sys
from collections import defaultdict

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append((b, 1))
        graph[b].append((a, 2))

    ans = 0
    visited = [False] * (n + 1)
    for i in range(1, n + 1):
        if not visited[i]:
            T = 0
            cnt = [0, 0, 0]
            ok = True
            stack = [(i, 0)]
            while stack:
                x, l = stack.pop()
                if not visited[x]:
                    visited[x] = True
                    cnt[l] += 1
                    T += 1
                    for v, c in graph[x]:
                        if not visited[v]:
                            stack.append((v, (l + c) % 3))
                        elif (l + c) % 3 != cnt.index(cnt[v]):
                            ok = False
            s = sum(cnt)
            if not ok:
                ans += s * s
            else:
                if all(cnt):
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                else:
                    ans += T // 2
    print(ans)

main()

