import sys
from io import StringIO
from typing import List, Tuple


class Solver:
    def __init__(self):
        self.MOD = 1000000007
        self.MAXN = 1000_006
    
    def solve(self, tc: int, N: int, K: int, A: List[int]) -> int:
        straight = []
        cycle = []
        vis = [False] * N
        curr = 0
        while not vis[curr]:
            vis[curr] = True
            curr = A[curr] - 1

        st = 0
        while st != curr:
            straight.append(st)
            st = A[st] - 1

        cycle.append(curr)
        curr = A[curr] - 1
        while curr != cycle[0]:
            cycle.append(curr)
            curr = A[curr] - 1

        if K < len(straight):
            return straight[K] + 1
        else:
            K -= len(straight)
            return cycle[K % len(cycle)] + 1


def main() -> None:
    T = int(input().strip())
    for _ in range(T):
        N, K = map(int, input().strip().split())
        A = list(map(int, input().strip().split()))
        solver = Solver()
        result = solver.solve(_, N, K, A)
        print(result)


if __name__ == "__main__":
    main()


