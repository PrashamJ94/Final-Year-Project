def linear_search(arr, n, key):
    i = 0
    arr.append(key)

    while arr[i] != key:
        i += 1

    arr.pop()
    return i != n


def main():
    n = int(input())
    s = [int(x) for x in input().split()]
    
    q = int(input())
    count = 0

    for _ in range(q):
        t = int(input())
        if linear_search(s, n, t):
            count += 1

    print(count)


if __name__ == "__main__":
    main()


