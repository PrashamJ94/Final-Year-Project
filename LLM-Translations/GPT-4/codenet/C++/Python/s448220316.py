
def read():
    k, f = 0, 1
    ch = input()
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = input()
    while '0' <= ch <= '9':
        k = k * 10 + int(ch) - int('0')
        ch = input()
    return k * f

def write(x):
    if x < 0:
        x = -x
        print('-', end='')
    if x > 9:
        write(x // 10)
    print(chr(x % 10 + ord('0')), end='')

def writeln(x):
    write(x)
    print("")

def main():
    n, m = read(), read()
    fa, v = [0] * (n + 1), [0] * (2 * n + 1)
    for i in range(1, n + 1):
        fa[i] = i
    for _ in range(1, m + 1):
        l, r, vi = read(), read(), read()
        li, ri = get(l, fa, v), get(r, fa, v)
        if li != ri:
            v[ri] = vi - v[r] + v[l]
            fa[ri] = li
        else:
            if v[r] - v[l] != vi:
                print("No")
                return
    print("Yes")

def get(x, fa, v):
    if x == fa[x]:
        return x
    f = get(fa[x], fa, v)
    v[x] += v[fa[x]]
    fa[x] = f
    return f

main()


