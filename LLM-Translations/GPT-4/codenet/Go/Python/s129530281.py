
import sys
from typing import List

class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    def init(self, n: int):
        self.n = n
        self.unit = [1]
        self.bucket = [[0] * n]

        chunk = 8
        while n > 1:
            n = (n - 1) // chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[-1] * chunk)
        self.h = len(self.unit)
        self.chunk = chunk

    def maximize(self, index: int, value: int):
        self.bucket[0][index] = value
        for self.i in range(self.h - 1):
            s = index - index % self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            parent = index // self.chunk
            maximum = max(self.bucket[self.i][s:t])
            self.bucket[self.i + 1][parent] = maximum
            index //= self.chunk

    def top(self) -> int:
        index = 0
        for self.i in range(self.h - 2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i + 1][index]:
                    index = i
                    break
        return index

def main():
    n, m = map(int, input().split())
    data = list(map(int, input().split()))

    seg = Segment()
    seg.init(n)
    for i in range(n):
        seg.maximize(i, data[i])
    for _ in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] // 2)

    ans = sum(seg.bucket[0])
    print(ans)

if __name__ == "__main__":
    main()


