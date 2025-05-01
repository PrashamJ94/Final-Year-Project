def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    m = min(numbers)
    M = max(numbers)
    c = sum(numbers)
    print(m, M, c)

if __name__ == "__main__":
    main()


