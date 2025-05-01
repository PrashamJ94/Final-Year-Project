import bisect

def main():
    a, b, q = map(int, input().split())
    s = [-10_000_000_000] + [int(input()) for _ in range(a)] + [20_000_000_000]
    t = [-10_000_000_000] + [int(input()) for _ in range(b)] + [20_000_000_000]
    for _ in range(q):
        x = int(input())
        sl = x - s[bisect.bisect_left(s, x) - 1]
        tl = x - t[bisect.bisect_left(t, x) - 1]
        sr = s[bisect.bisect_left(s, x)] - x
        tr = t[bisect.bisect_left(t, x)] - x
        print(min(
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        ))

if __name__ == '__main__':
    main()


