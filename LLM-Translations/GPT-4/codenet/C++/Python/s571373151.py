
def main():
    n, m = map(int, input().split())

    foods = [0] * m

    for i in range(n):
        k, *temp_list = map(int, input().split())

        for temp in temp_list:
            temp -= 1
            foods[temp] += 1

    ans = 0
    for elem in foods:
        if elem == n:
            ans += 1

    print(ans)


if __name__ == "__main__":
    main()


