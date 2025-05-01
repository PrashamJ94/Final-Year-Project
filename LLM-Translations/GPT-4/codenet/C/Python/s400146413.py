def linear_search(S, n, key):
    i = 0
    count = 0
    while S[i] != key:
        i += 1
        if i >= n:
            count = 1
            return count
    return count

def main():
    count = 0

    n = int(input())
    S = list(map(int, input().split()))

    q = int(input())
    T = list(map(int, input().split()))

    for j in range(q):
        key = T[j]
        if linear_search(S, n, key) == 0:
            count += 1

    print(count)

if __name__ == "__main__":
    main()


