import sys
from functools import reduce

MOD = int(1e9) + 7

def main():
    n = int(input().strip())
    s = input().strip()
    cnt = [1] * 26

    for i in range(n):
        cnt[ord(s[i]) - ord('a')] += 1

    ans = reduce(lambda x, y: x * y % MOD, cnt)

    print(ans - 1)

main()


