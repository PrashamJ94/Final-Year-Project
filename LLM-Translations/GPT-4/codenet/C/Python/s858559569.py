
from typing import List, Tuple

N = 4

class Pazz:
    def __init__(self, P: List[List[int]]):
        self.P = P

def Heu(Q: Pazz) -> int:
    sum = 0
    for i in range(N):
        for j in range(N):
            if Q.P[i][j] == 0:
                continue

            hx = (Q.P[i][j] - 1) % N - j
            hy = (Q.P[i][j] - 1) // N - i

            if hx < 0:
                sum -= hx
            else:
                sum += hx

            if hy < 0:
                sum -= hy
            else:
                sum += hy
    return sum

def dfs(x: int, y: int, max: int, count: int, n: int, Q: Pazz) -> int:
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    h = Heu(Q)

    if h == 0:
        return count
    if count + h > max:
        return -1

    ans = -1

    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]

        if ((i == (n + 2) % 4 and n != -1) or not (0 <= x0 < N and 0 <= y0 < N)):
            continue
        
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

        ans = dfs(x0, y0, max, count + 1, i, Q)

        if ans != -1:
            return ans
        
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

    return -1

def main() -> None:
    kx, ky = -1, -1
    P = []
    for i in range(N):
        row = list(map(int, input().split()))
        P.append(row)
        if 0 in row:
            kx = row.index(0)
            ky = i

    Q = Pazz(P)

    for i in range(1, 46):
        ans = dfs(kx, ky, i, 0, -1, Q)
        if ans != -1:
            print(ans)
            break

if __name__ == "__main__":
    main()



