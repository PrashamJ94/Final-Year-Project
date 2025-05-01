
from sys import stdin

def main():
    s = input().strip()
    cum = [0] * (len(s) + 1)

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            cum[i] = cum[i - 1] + 1
        else:
            cum[i] = cum[i - 1]

    q = int(input().strip())

    while q:
        l, r = map(int, input().strip().split())
        r -= 1
        print(cum[r] - cum[l - 1])
        q -= 1

if __name__ == "__main__":
    main()


