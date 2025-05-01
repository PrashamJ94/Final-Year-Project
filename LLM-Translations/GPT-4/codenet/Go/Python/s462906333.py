import sys
from typing import List, Tuple

INF = int(1e14)

def main() -> None:
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    v = a[:]
    ans = INF
    for k in range(n):
        kans = 0
        for i in range(n):
            if i - k < 0:
                v[i] = min(v[i], a[n + i - k])
            else:
                v[i] = min(v[i], a[i - k])
            kans += v[i]
        ans = min(ans, kans + k * x)

    print(ans)

if __name__ == "__main__":
    main()


