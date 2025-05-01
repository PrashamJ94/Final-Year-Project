import sys
from typing import List, Tuple
import bisect

def main():
    n, x = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A.sort()

    ans = 0
    for i in range(n):
        if x >= A[i]:
            ans += 1
            x -= A[i]
        else:
            break
    if ans == n and x > 0:
        ans -= 1
    print(ans)

if __name__ == '__main__':
    main()


