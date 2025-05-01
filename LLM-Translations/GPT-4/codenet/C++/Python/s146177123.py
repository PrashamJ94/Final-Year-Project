
def main():
    seg = [
        [0, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 1, 1, 0],
        [1, 0, 1, 1, 0, 1, 1],
        [1, 0, 0, 1, 1, 1, 1],
        [1, 1, 0, 0, 1, 1, 0],
        [1, 1, 0, 1, 1, 0, 1],
        [1, 1, 1, 1, 1, 0, 1],
        [0, 1, 0, 0, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1],
        [1, 1, 0, 1, 1, 1, 1]
    ]

    while True:
        n = int(input())
        if n == -1:
            break

        st = [0] * 7

        for _ in range(n):
            t = int(input())
            ans = [0] * 7

            for i in range(7):
                ans[i] = st[i] ^ seg[t][i]
                st[i] = seg[t][i]

            print("".join(str(bit) for bit in ans))

if __name__ == "__main__":
    main()


