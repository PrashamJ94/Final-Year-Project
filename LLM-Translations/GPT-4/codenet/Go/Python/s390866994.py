import sys
from typing import List, Tuple

def getInts() -> List[int]:
    return list(map(int, sys.stdin.readline().split()))

def main() -> None:
    N, C, K = getInts()
    t = [int(input()) for _ in range(N)]

    t.sort()

    ans = 1
    cnt = 1
    end = t[0] + K
    for i in range(1, N):
        if cnt < C and t[i] <= end:
            cnt += 1
        else:
            cnt = 1
            end = t[i] + K
            ans += 1

    print(ans)

main()

