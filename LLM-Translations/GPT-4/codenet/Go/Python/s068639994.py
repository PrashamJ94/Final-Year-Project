def mainFn():
    n = int(input())
    ls = list(map(int, input().split()))
    lsRev = sorted(ls, reverse=True)
    ls.sort()

    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            x, y = q - p, q + p

            l = next((k for k, el in enumerate(ls) if el > x), len(ls))
            r = len(ls) - next((k for k, el in enumerate(lsRev) if el < y), len(lsRev))

            sum = r - l
            if (i >= l) and (i <= r):
                sum -= 1
            if (j >= l) and (j <= r):
                sum -= 1
            sum = max(0, sum)
            ans += sum

    ans //= 3
    print(ans)

mainFn()


