
from itertools import accumulate
from collections import Counter
from math import comb

def main():
    n = int(input())
    a = list(map(int, input().split()))

    s = [0] + list(accumulate(a))
    s.sort()

    counter = Counter(s)
    ans = 0

    for count in counter.values():
        if count > 1:
            ans += comb(count, 2)

    print(ans)

if __name__ == "__main__":
    main()


