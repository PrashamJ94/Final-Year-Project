def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    tmpa = [0] * 200000
    light = [0] * 200010

    for i in range(n):
        r = i - a[i]
        l = i + a[i]
        light[max(0, r)] += 1
        light[min(n + 1, l + 1)] -= 1

    for _ in range(k):
        sum = 0
        for j in range(n):
            tmpa[j] = a[j]
            sum += light[j]
            a[j] = sum

        for j in range(n):
            r = j - tmpa[j]
            l = j + tmpa[j]
            light[max(0, r)] -= 1
            light[min(n + 1, l + 1)] += 1
            r = j - a[j]
            l = j + a[j]
            light[max(0, r)] += 1
            light[min(n + 1, l + 1)] -= 1

        isSame = True
        for j in range(n - 1):
            if a[j] != a[j + 1]:
                isSame = False
                break

        if isSame and a[0] == n:
            break

    print(" ".join(map(str, a)))

main()

