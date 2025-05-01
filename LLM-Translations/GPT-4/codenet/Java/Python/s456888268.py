import sys
from typing import List

def solve(s: str) -> int:
    n = len(s)
    ans = 0
    cnt = 0
    for i in range(n):
        if s[i] == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    return n - 2 * ans

def main():
    s = input().strip()
    print(solve(s))

if __name__ == "__main__":
    main()


