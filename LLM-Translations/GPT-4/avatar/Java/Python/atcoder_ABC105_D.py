
from collections import defaultdict

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    dp = defaultdict(int)
    ans = 0
    base = 0
    for i in range(n):
        base = (base - a[i] % m + m) % m
        dp[(base + a[i]) % m] += 1
        ans += dp.get(base, 0)
    print(ans)

if __name__ == "__main__":
    main()

##End of Code
