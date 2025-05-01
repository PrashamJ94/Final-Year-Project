
import sys
from typing import List, Tuple

def main() -> None:
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    ans = 0
    i = 0
    while i < n:
        l, r = i, i+1
        while r+1 < n and (a[r]-a[l])*(a[r+1]-a[r]) >= 0:
            r += 1
        ans += 1
        i = r

    print(ans)

if __name__ == "__main__":
    main()


