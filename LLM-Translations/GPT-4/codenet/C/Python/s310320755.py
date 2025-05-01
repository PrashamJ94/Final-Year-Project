
def main():
    arr = [[0] * 16 for _ in range(16)]

    while True:
        n = int(input())
        if n == 0:
            break
        flag = 1
        r = (n + 1) // 2 + 1
        c = (n + 1) // 2
        arr[r][c] = cnt = 1

        while cnt != n * n + 1:
            cnt += 1
            if flag:
                r += 1
                c += 1
                if c > n:
                    c = 1

                if r > n:
                    r = 1

                if arr[r][c]:
                    flag = 0
                    cnt -= 1
                else:
                    arr[r][c] = cnt
            else:
                r += 1
                c -= 1
                if c < 1:
                    c = n

                if r > n:
                    r = 1

                if arr[r][c]:
                    flag = 0
                else:
                    arr[r][c] = cnt
                    flag = 1

        for r in range(1, n + 1):
            for c in range(1, n + 1):
                print(f"{arr[r][c]:4}", end="")
                arr[r][c] = 0
                if c == n:
                    print()

if __name__ == "__main__":
    main()


