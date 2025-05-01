import sys
from typing import List, Tuple

def main() -> None:
    N, M = map(int, input().split())

    shortage = [0] * M

    for i in range(M):
        A = int(input())
        shortage[i] = N - A if N > A else 0

    shortage.sort()

    ans = 0

    for i in range(M - 1):
        ans += shortage[i]

    print(ans)

if __name__ == "__main__":
    main()


