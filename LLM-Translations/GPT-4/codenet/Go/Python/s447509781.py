import sys
from typing import List, Tuple

def main():
    n, s = read_input()
    u = [False] * n
    m, f = 0, 0
    for c in range(1, n - 1):
        f = 0
        k = 0
        while c < (n - 1 - k * c):
            u[k * c] = True
            if u[n - 1 - k * c]:
                break
            f += s[n - 1 - k * c] + s[k * c]
            if m < f:
                m = f
            k += 1

        for i in range(n):
            if k * c < n - 1:
                u[k * c] = False
            else:
                break
    print(m)

def read_input() -> Tuple[int, List[int]]:
    n = int(input().strip())
    s = list(map(int, input().strip().split()))
    return n, s

if __name__ == '__main__':
    main()


