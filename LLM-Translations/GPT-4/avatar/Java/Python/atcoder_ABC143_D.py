import bisect

def main():
    N = int(input())
    L = sorted(list(map(int, input().split())))

    count = 0
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            res = bisect.bisect_left(L, a + b) - (j + 1)
            count += res

    print(count)

if __name__ == "__main__":
    main()


