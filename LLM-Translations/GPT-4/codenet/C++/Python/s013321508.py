import bisect

def main():
    N, M = map(int, input().split())
    L = list(map(int, input().split()))

    L.sort()

    for _ in range(M):
        max_L = L[-1]
        if max_L == 0:
            break

        max_L //= 2
        index = bisect.bisect_left(L, max_L)
        L.insert(index, max_L)
        L.pop()

    ans = sum(L)
    print(ans)

if __name__ == "__main__":
    main()


