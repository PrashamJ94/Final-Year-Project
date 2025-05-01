
def main():
    X, N = map(int, input().split())
    if N == 0:
        print(X)
        return

    plus = [i for i in range(256)]
    minus = [-i for i in range(256)]
    unavailable = set(map(int, input().split()))

    for i in unavailable:
        plus[i] = 0

    i_min = 0
    min_difference = 1000
    for i in range(255, -1, -1):
        if plus[i] == 0 and i > 0:
            continue
        k = abs(X - plus[i])
        if k <= min_difference:
            min_difference = k
            i_min = i

    print(i_min)

if __name__ == "__main__":
    main()


