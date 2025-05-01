import sys
from collections import defaultdict

def main():
    m, s, f = map(int, input().split())
    max_t = -1
    intervals = defaultdict(list)

    for _ in range(m):
        k, a, b = map(int, input().split())
        intervals[k] = [a, b]
        max_t = max(max_t, k)

    actions = []
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    cur = s
    a = -1
    b = -1

    for t in range(1, max_t + 1):
        if t in intervals:
            a, b = intervals[t]

        if t in intervals and ((cur >= a and cur <= b) or (cur + d >= a and cur + d <= b)):
            actions.append('X')
        else:
            actions.append(M)
            cur += d

        if cur == f:
            break

    while cur != f:
        actions.append(M)
        cur += d

    print("".join(actions))

if __name__ == "__main__":
    main()


