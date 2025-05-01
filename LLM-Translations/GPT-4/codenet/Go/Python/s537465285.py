import sys
from typing import List

def input():
    return sys.stdin.readline().strip()

def Bipartite(S: List[str]) -> bool:
    N = len(S)
    D = [0] * N
    D[0] = 1
    Q = [0] * N
    ret = True
    pos = 1
    for i in range(N):
        if not ret:
            break
        q = Q[i]
        for j, s in enumerate(S[q]):
            if s == '0':
                continue
            if D[j] == 0:
                D[j] = D[q] + 1
                Q[pos] = j
                pos += 1
                continue
            if D[j] % 2 == D[q] % 2:
                ret = False
                break
    return ret

def WarshallFloyd(S: List[str]) -> int:
    N = len(S)
    G = [[0 if i == j else N for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            if S[i][j] == '0':
                G[i][j] = N
            else:
                G[i][j] = 1

    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]

    ans = 0
    for i in range(N):
        for j in range(N):
            if ans < G[i][j]:
                ans = G[i][j]
    return ans + 1

def main():
    N = int(input())
    S = [input() for _ in range(N)]
    if not Bipartite(S):
        print(-1)
    else:
        print(WarshallFloyd(S))

if __name__ == "__main__":
    main()


