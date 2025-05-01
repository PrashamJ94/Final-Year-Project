
def main():
    k = int(input())
    a = list(map(int, input().split()))

    min_val, max_val = 2, 3

    if a[-1] != 2:
        print(-1)
        return

    for i in range(k-2, -1, -1):
        if a[i] > max_val:
            print(-1)
            return
        else:
            max_val = ((max_val // a[i]) + 1) * a[i] - 1
            if min_val % a[i] != 0:
                min_val = ((min_val // a[i]) + 1) * a[i]

        if max_val <= min_val:
            print(-1)
            return

    print(min_val, max_val)

if __name__ == "__main__":
    main()


