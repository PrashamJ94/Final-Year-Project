def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    ans = sum(a[:k])
    print(ans)

if __name__ == "__main__":
    main()


