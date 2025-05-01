def main():
    A, B = map(int, input().split())

    ans = 0
    if 6 <= A <= 12:
        ans = B // 2
    elif A > 12:
        ans = B
    print(ans)

if __name__ == "__main__":
    main()


