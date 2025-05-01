def main():
    n = int(input())
    a = [0] + [int(x) for x in input().split()]
    count = [0] * n

    for i in range(1, n):
        count[a[i] - 1] += 1

    for i in range(n):
        print(count[i])

if __name__ == "__main__":
    main()


