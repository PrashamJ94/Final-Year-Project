import sys
from operator import attrgetter

def main():
    n = int(input())
    class Arm:
        def __init__(self, l, r):
            self.l = l
            self.r = r

    as_ = []
    for _ in range(n):
        x, l = map(int, input().split())
        as_.append(Arm(x - l, x + l))

    as_.sort(key=attrgetter('r'))

    ans = 1
    r = as_[0].r
    for i in range(1, n):
        if as_[i].l >= r:
            ans += 1
            r = as_[i].r

    print(ans)

if __name__ == "__main__":
    main()


