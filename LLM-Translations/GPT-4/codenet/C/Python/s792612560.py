def main():
    n = int(input())
    m = n
    n -= 1
    for _ in range(n, 1, -1):
        m *= n
        n -= 1
    print(m)

if __name__ == "__main__":
    main()


