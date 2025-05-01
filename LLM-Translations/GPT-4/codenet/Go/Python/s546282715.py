import sys
from collections import defaultdict

def get_next_word(file):
    return file.readline().strip()

def get_next_int(file):
    return int(get_next_word(file))

def main():
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], "r")
    else:
        fp = sys.stdin

    n = get_next_int(fp)
    m = get_next_int(fp)
    aa = defaultdict(int)
    for i in range(m):
        aa[get_next_int(fp)] = 1

    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        for ii in range(1, 3):
            if i + ii > n:
                break

            if aa[i + ii]:
                continue

            dp[i + ii] += dp[i]
            dp[i + ii] %= 1000000007

    print(dp[n])

if __name__ == "__main__":
    main()


