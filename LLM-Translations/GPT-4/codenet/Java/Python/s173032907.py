import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    cost1 = 0
    cost2 = 0
    current1 = 0
    current2 = 0
    dp1 = [0] * n
    dp2 = [0] * n
    for i in range(n):
        j = n - 1 - i
        cost1 += abs(a[i] - current1)
        current1 = a[i]
        dp1[i] = cost1
        cost2 += abs(a[j] - current2)
        current2 = a[j]
        dp2[j] = cost2

    for i in range(n):
        if i == 0:
            print(dp2[i + 1] + abs(a[1]))
        elif i == n - 1:
            print(dp1[i - 1] + abs(a[i - 1]))
        else:
            print(dp1[i - 1] + dp2[i + 1] + abs(a[i - 1] - a[i + 1]))

if __name__ == "__main__":
    main()


