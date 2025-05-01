
def main():
    n, k, x, y = map(int, input().split())
    total = 0
    for i in range(1, n + 1):
        if i > k:
            total += y
        else:
            total += x
    print(total)

if __name__ == "__main__":
    main()


