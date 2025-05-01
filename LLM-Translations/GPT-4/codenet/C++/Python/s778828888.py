def main():
    n, m, x = map(int, input().split())
    a = [0] * 105
    temp_list = list(map(int, input().split()))

    for i in range(m):
        temp = temp_list[i]
        a[temp] = 1

    ansl, ansr = 0, 0
    for i in range(x, n + 1):
        ansr += a[i]
    for i in range(x, -1, -1):
        ansl += a[i]

    print(min(ansl, ansr))

if __name__ == "__main__":
    main()


