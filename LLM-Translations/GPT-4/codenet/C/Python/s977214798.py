def nextint(s):
    num = ''
    sign = 1
    while len(s) > 0:
        c = s.pop(0)
        if c == '-':
            sign = -1
        elif c.isdigit():
            num += c
        elif num != '':
            break
    return sign * int(num)

def p(a, b, n):
    if a < b:
        return a + b * n
    else:
        return b + a * n

def f(from_, e1, e2, d, b):
    if b[from_]:
        return -1
    if d[from_]:
        return d[from_]
    b[from_] = True
    max_ = 0
    for to in (e1[from_], e2[from_]):
        if to != 0:
            now = f(to, e1, e2, d, b)
            if now < 0:
                return now
            if now > max_:
                max_ = now
    b[from_] = False
    d[from_] = max_ + 1
    return d[from_]

def main():
    s = list(input().strip())
    n = nextint(s)
    a = [[nextint(s) - 1 for _ in range(n - 1)] for _ in range(n)]
    e1 = [0] * (n * n)
    e2 = [0] * (n * n)
    d = [0] * (n * n)
    b = [False] * (n * n)

    for i in range(n):
        for j in range(n - 2):
            from_ = p(i, a[i][j], n)
            to = p(i, a[i][j + 1], n)
            if e1[from_] == 0:
                e1[from_] = to
            elif e2[from_] == 0:
                e2[from_] = to
            else:
                print(-1)
                return

    ans = 0
    for i in range(n):
        from_ = p(i, a[i][0], n)
        now = f(from_, e1, e2, d, b)
        if now < 0:
            ans = -1
            break
        if now > ans:
            ans = now

    print(ans)

main()


