import sys
from collections import OrderedDict

def main():
    a = [int(input().strip()) for _ in range(5)]
    r = [x % 10 for x in a]
    map = OrderedDict(sorted({(10 - x % 10): x for x in a if x % 10 != 0}.items()))

    if not map:
        print(sum(a))
        return

    last = list(map.values())[-1]
    idx = a.index(last)
    ans = 0

    for i in range(len(a)):
        if i != idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])

    ans += last
    print(ans)

if __name__ == "__main__":
    main()


