import sys
from typing import List, Tuple

def main() -> None:
    n = int(input().strip())
    A = list(map(int, input().strip().split()))
    div = 10**9 + 7
    ans = 0

    for i in range(60):
        count1 = 0
        for a in A:
            if (a >> i) & 1 == 1:
                count1 += 1
        a = count1 * (n - count1)
        for _ in range(i):
            a = (a << 1) % div
        ans += a
        ans %= div

    print(ans)

if __name__ == "__main__":
    main()


