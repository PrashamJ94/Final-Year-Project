
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s


def main():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    fw = FenwickTree(n)
    for i in range(n):
        fw.add(i, a[i])

    for _ in range(q):
        t, *args = map(int, input().split())
        if t == 0:
            p, x = args
            fw.add(p, x)
        else:
            l, r = args
            print(fw.sum(l, r))


if __name__ == "__main__":
    main()



