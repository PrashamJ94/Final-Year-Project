def main():
    n = int(input())
    sum = 0
    a = list(map(int, input().split()))
    for i in range(1, n):
        if a[i - 1] > a[i]:
            sum += a[i - 1] - a[i]
            a[i] = a[i - 1]
    print(sum)

if __name__ == "__main__":
    main()


