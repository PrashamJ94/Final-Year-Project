import sys
from typing import List, Tuple

def solve(n: int, a: List[int]) -> Tuple[int, List[Tuple[int, int]]]:
    r = []
    m = 0 
    for i in range(1, n):
        if abs(a[m]) < abs(a[i]):
            m = i 
    for i in range(0, n): 
        if a[m] >= 0 ^ a[i] >= 0:
            r.append((m + 1 , i + 1))
    if a[m] >= 0:
        for i in range(1, n):
            r.append((i, i + 1))
    else:
        for i in range(n, 1, -1):
            r.append((i , i - 1))
    return len(r), r

def main():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    l, r = solve(n, a)
    print(l)
    for x in r:
        print(*x)

if __name__ == "__main__":
    main()


