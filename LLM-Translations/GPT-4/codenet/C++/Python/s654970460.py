def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    print(a[n-1], end="")
    for i in range(1, n):
        print(" " + str(a[n-i-1]), end="")
    print()

if __name__ == "__main__":
    main()


