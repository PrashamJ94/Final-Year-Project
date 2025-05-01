def main():
    n, x = map(int, input().split())
    l = list(map(int, input().split()))

    tmp_sum = 0
    rs = 0
    for i, v in enumerate(l):
        tmp_sum += v
        if i >= n:
            rs = n
            break
        if tmp_sum <= x:
            rs = i + 2
        elif tmp_sum > x:
            break

    print(rs)

if __name__ == "__main__":
    main()


