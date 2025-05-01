import sys
from bisect import bisect_left

INF = int(1e11)

def main():
    A, B, Q, *data = map(int, sys.stdin.buffer.read().split())
    s = [-INF] + data[:A] + [INF]
    t = [-INF] + data[A:A + B] + [INF]
    queries = data[A + B:]

    for x in queries:
        b, d = bisect_left(s, x), bisect_left(t, x)
        res = INF
        for S in [s[b - 1], s[b]]:
            for T in [t[d - 1], t[d]]:
                d1, d2 = abs(S - x) + abs(T - S), abs(T - x) + abs(S - T)
                res = min(res, min(d1, d2))
        print(res)

def abs(x):
    return int(abs(float(x)))

def min(x, y):
    return int(min(float(x), float(y)))

def max(x, y):
    return int(max(float(x), float(y)))

main()


