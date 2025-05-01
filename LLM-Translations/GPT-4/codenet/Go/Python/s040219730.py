
from sys import stdin
from bisect import bisect_left, bisect_right
from itertools import accumulate

def main():
    n, q = map(int, stdin.readline().split())
    C = list(map(int, stdin.readline().split()))

    queries = [tuple(map(int, stdin.readline().split())) for _ in range(q)]

    P = [-1] * (n + 1)
    answers = [0] * q

    queries = sorted(enumerate(queries), key=lambda x: x[1][1])

    ft = FenwickTree(n + 1)

    k = 0
    for idx, (l, r) in queries:
        while k < r:
            if P[C[k]] != -1:
                ft.add(P[C[k]] + 1, -1)
            P[C[k]] = k
            ft.add(k + 1, 1)
            k += 1

        answers[idx] = ft.sum(r) - ft.sum(l - 1)

    for ans in answers:
        print(ans)

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)
        self.n = n

    def add(self, i, x):
        while i <= self.n:
            self.dat[i] += x
            i += i & (-i)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.dat[i]
            i -= i & (-i)
        return s

if __name__ == "__main__":
    main()


