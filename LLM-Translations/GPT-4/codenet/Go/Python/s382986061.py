def main():
    N, K = map(int, input().split())
    as_dict = {i: 0 for i in range(1, N+1)}
    for _ in range(K):
        d, *a = map(int, input().split())
        for j in a:
            as_dict[j] += 1
    ans = sum(1 for v in as_dict.values() if v == 0)
    print(ans)

if __name__ == "__main__":
    main()


