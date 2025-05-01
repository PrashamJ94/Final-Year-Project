
from sys import stdin

def main():
    def solve():
        ans = 0
        n = int(input().strip())
        for i in range(1, n + 1):
            ans += i * 1 * (n - i + 1)
        for _ in range(1, n):
            u, v = map(int, input().strip().split())
            a = max(u, v)
            b = min(u, v)
            ans -= b * 1 * (n - a + 1)
        print(ans)

    t = 1
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()

#
