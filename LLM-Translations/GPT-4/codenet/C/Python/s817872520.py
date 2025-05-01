import sys

def getint(p):
    n = 0
    if p[0] == '-':
        p = p[1:]
        while p[0].isdigit():
            n = (n<<3) + (n<<1) + (ord(p[0]) & 0xf)
            p = p[1:]
        return -n
    while p[0].isdigit():
        n = (n<<3) + (n<<1) + (ord(p[0]) & 0xf)
        p = p[1:]
    return n, p

def main():
    w = int(input().strip())
    buf = input().strip()
    p = buf
    ans = 0
    f = 0
    a = [0] * (w + 2)
    b = [0] * (w + 2)
    for i in range(1, w + 1):
        a[i], p = getint(p)
        p = p[1:]
        k = a[i]
        if k == 0:
            f |= 1
        elif k < 0:
            f |= 2
        else:
            ans += k
    if ans == 0 or (f & 1) == 0:
        print("0")
        return
    if (f & 2) == 0:
        print(ans)
        return

    close = 0
    f = 0
    for i in range(1, w + 1):
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (i-f) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (i-f)
                if k < 0:
                    k = 0
                b[i] = k

    close = 0
    f = w
    for i in range(w, 0, -1):
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (f-i) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (f-i)
                if k < 0:
                    k = 0
                if k > b[i]:
                    b[i] = k

    for i in range(1, w + 1):
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]
    print(ans)

if __name__ == "__main__":
    main()


