def main():
    while True:
        n, r = map(int, input().split())
        if n == 0 and r == 0:
            break

        a = [n - i for i in range(n)]
        b = [0] * n

        for i in range(r):
            b = a.copy()
            p, c = map(int, input().split())

            for j in range(c):
                a[j] = b[p - 1 + j]

            for j in range(c, c + p - 1):
                a[j] = b[j - c]

        print(a[0])

if __name__ == "__main__":
    main()


