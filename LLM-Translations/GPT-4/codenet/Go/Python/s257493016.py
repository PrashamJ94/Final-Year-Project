
def min_value(n):
    if len(n) == 0:
        raise ValueError("len == 0")
    r = n[0]
    for i in range(1, len(n)):
        if n[i] <= r:
            r = n[i]
    return r


def main():
    H, N = map(int, input().split())
    dp = [2100000000] * (H + 10001)
    for l in range(1, H + 10001):
        dp[l] = 2100000000
    amax = 0
    for _ in range(N):
        A, B = map(int, input().split())
        if A >= amax:
            amax = A
        dp[A] = min_value([dp[A], B])
        for j in range(A + 1, H + A + 1):
            dp[j] = min_value([dp[j], dp[j - A] + B])
    print(min_value(dp[H:H + amax + 1]))


if __name__ == '__main__':
    main()


