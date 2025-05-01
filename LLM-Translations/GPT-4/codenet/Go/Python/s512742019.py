import sys
from collections import deque
from math import ceil

# Input
def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    N, D, A = read_ints()
    M = [tuple(read_ints()) for _ in range(N)]
    M.sort()

    q = deque()
    ans = 0
    total = 0

    for i in range(N):
        x, h = M[i]

        while q and q[0][0] < x:
            total -= q.popleft()[1]

        if total < h:
            h -= total
            count = ceil(h / A)
            ans += count
            damage = count * A
            q.append((x + 2 * D, damage))
            total += damage

    print(ans)

if __name__ == "__main__":
    main()


