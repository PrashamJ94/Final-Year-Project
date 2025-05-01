import sys
from typing import List, Tuple

def main():
    MOD = 1000000007

    def input(): return sys.stdin.readline().strip()
    def iinput(): return int(input())
    def linput(): return list(map(int, input().split()))
    def lcm(m: int, n: int) -> int: return m * n // gcd(m, n)
    def gcd(m: int, n: int) -> int: return m if n == 0 else gcd(n, m % n)

    n = iinput()
    l = linput()
    l.sort()

    print(l[n//2] - l[n//2 - 1])

if __name__ == "__main__":
    main()


