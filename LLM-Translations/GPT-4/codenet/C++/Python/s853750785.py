
from typing import List, Tuple

def main(N: int, M: int, H: List[int], UV: List[Tuple[int, int]]) -> int:
    G = [[] for _ in range(N)]
    for u, v in UV:
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)

    ans = 0
    for u in range(N):
        flag = True
        for v in G[u]:
            if H[u] <= H[v]:
                flag = False
        if flag:
            ans += 1
    return ans


