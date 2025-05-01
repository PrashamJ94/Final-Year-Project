
def main():
    while True:
        n, r = map(int, input().split())
        if not n and not r:
            break

        a = [i + 1 for i in range(n)]

        for _ in range(r):
            p, c = map(int, input().split())

            b = a[n - p - c + 1:n - p - c + 1 + c]
            a[n - p - c + 1:n - p - c + 1 + len(b)] = a[n - p + 1:n - p + 1 + len(b) - c]
            a[n - p - c + 1 + len(b) - c:n - p - c + 1 + len(b)] = b

        print(a[n - 1])

if __name__ == "__main__":
    main()


