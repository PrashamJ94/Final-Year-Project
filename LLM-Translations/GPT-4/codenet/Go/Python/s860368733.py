def main():
    n, m = map(int, input().split())
    h = list(map(int, input().split()))
    counter = {}
    for _ in range(m):
        a, b = map(int, input().split())
        if h[a - 1] < h[b - 1]:
            counter[a] = None
        elif h[a - 1] > h[b - 1]:
            counter[b] = None
        elif h[a - 1] == h[b - 1]:
            counter[a] = None
            counter[b] = None
    print(n - len(counter))

if __name__ == "__main__":
    main()


