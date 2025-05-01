def main():
    N, D = map(int, input().split())  # N, D are integers between 1 and 20

    ans = N // (D * 2 + 1)
    rem = N % (D * 2 + 1)

    if rem != 0:
        ans = ans + 1

    print(ans)

if __name__ == "__main__":
    main()


