import sys
from collections import defaultdict
from bisect import bisect_left

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    def is_possible(k):
        s = defaultdict(int)
        current = 0
        for ai in a:
            if ai <= current:
                if k == 1:
                    return False
                while s and max(s) >= ai:
                    del s[max(s)]
                p = ai - 1
                while True:
                    if p < 0:
                        return False
                    s[p] += 1
                    if s[p] == k:
                        del s[p]
                        p -= 1
                    else:
                        break
            current = ai
        return True

    ng = 0
    ok = n
    while ok - ng > 1:
        k = (ng + ok) // 2
        if is_possible(k):
            ok = k
        else:
            ng = k

    print(ok)

if __name__ == "__main__":
    main()


