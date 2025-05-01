def main():
    a, b = map(int, input().split())

    ans = 0
    if a >= 13:
        ans = b
    elif a >= 6:
        ans = b // 2

    print(ans)

if __name__ == '__main__':
    main()


