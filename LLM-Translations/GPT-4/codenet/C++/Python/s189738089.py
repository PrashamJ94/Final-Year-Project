import sys
input = sys.stdin.readline

def chmin(a, b):
    return min(a, b)

INF = 1 << 30

def main():
    N, K = map(int, input().split())
    h = list(map(int, input().split()))

    dp = [INF] * 101000
    dp[0] = 0

    for i in range(N):
        for j in range(1, K + 1):
            if i + j < N:
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    print(dp[N - 1])

if __name__ == "__main__":
    main()


