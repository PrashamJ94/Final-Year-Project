import sys
from typing import List

class TSize:
    def __init__(self, r: int = 0, c: int = 0):
        self.r = r
        self.c = c

class TMcmSolver:
    def __init__(self, chain: List[TSize]):
        self.FMemo = [[0 for _ in range(len(chain))] for _ in range(len(chain))]
        self.FChain = chain

    def count(self, left: TSize, right: TSize) -> int:
        return left.r * right.c * left.c

    def solve(self, s: int, l: int) -> int:
        if s == l:
            return 0
        if self.FMemo[s][l] != 0:
            return self.FMemo[s][l]
        if s + 1 == l:
            self.FMemo[s][l] = self.count(self.FChain[s], self.FChain[l])
        else:
            min_val = sys.maxsize
            for i in range(s, l):
                c = self.solve(s, i) + self.count(TSize(self.FChain[s].r, self.FChain[i].c), TSize(self.FChain[i+1].r, self.FChain[l].c)) + self.solve(i+1, l)
                min_val = min(min_val, c)
            self.FMemo[s][l] = min_val
        return self.FMemo[s][l]

    def answer(self) -> int:
        return self.solve(0, len(self.FMemo) - 1)

def main():
    n = int(input().strip())
    if n == 1:
        print(0)
        return
    chain = [TSize() for _ in range(n)]
    for i in range(n):
        chain[i].r, chain[i].c = map(int, input().strip().split())
    solver = TMcmSolver(chain)
    print(solver.answer())

if __name__ == "__main__":
    main()


