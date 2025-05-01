
from sys import stdin

MOD = 1000000007

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    acc = [0] * (n + 1)

    for i in range(n):
        acc[i + 1] = acc[i] + a[i]
        acc[i + 1] %= MOD

    ans = 0
    for i in range(n):
        ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD
        ans %= MOD
    print(ans)

if __name__ == "__main__":
    main()


