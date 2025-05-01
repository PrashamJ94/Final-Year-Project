def run():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [0] * (k + 1)

    for i in range(1, k + 1):
        win = 0
        for j in range(n):
            if a[j] <= i:
                if dp[i - a[j]] == 0:
                    win = 1
            else:
                break
        dp[i] = win

    print("First" if dp[k] else "Second")

if __name__ == "__main__":
    run()

