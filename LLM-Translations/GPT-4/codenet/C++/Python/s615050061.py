import sys
from collections import defaultdict

def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1
    t = 1
    while k:
        if k & 1:
            t = t * a
        a = a * a
        k >>= 1
    return t

def main():
    n, s = input().strip().split()
    n = int(n)
    s = ' ' + s

    B = 13131
    N = 500000 + 7

    f = [0] * (n + 1)
    g = [0] * (n + 1)
    cnt = 0
    mapping = defaultdict(int)

    for i in range(1, n + 1):
        if s[i] == '+' or s[i] == '-':
            f[i] = f[i - 1] + (1 if s[i] == '+' else -1) * pow(B, g[i - 1])
            g[i] = g[i - 1]
        else:
            f[i] = f[i - 1]
            g[i] = g[i - 1] + (-1 if s[i] == '<' else 1)

    for i in range(n, 0, -1):
        mapping[f[i]] += 1
        cnt += mapping[f[n] * pow(B, g[i - 1]) + f[i - 1]]

    print(cnt)

if __name__ == "__main__":
    main()


