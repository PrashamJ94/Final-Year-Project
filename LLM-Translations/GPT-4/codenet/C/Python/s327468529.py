
from sys import stdin

def main():
    n = int(input().strip())
    s = input().strip()

    cnt = [0, 0, 0]
    pcnt = 0
    result = 1
    MOD = 998244353

    for c in s:
        if c == 'R':
            v = 0
        elif c == 'G':
            v = 1
        else:
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            pcnt -= 1
            result %= MOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= MOD
                pcnt += 1

            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % MOD

    print(result)

if __name__ == '__main__':
    main()


