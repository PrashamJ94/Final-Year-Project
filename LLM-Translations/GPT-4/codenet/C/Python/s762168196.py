def main():
    n = int(input())
    a = list(map(int, input().split()))
    _sum = sum(a)
    _min = min(a)
    _max = max(a)
    print(_min, _max, _sum)

if __name__ == "__main__":
    main()


