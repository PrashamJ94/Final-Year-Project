def bubble_sort(arr):
    n = len(arr)
    count = 0

    for i in range(n - 1):
        for j in range(n - 1, i, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                count += 1

    return count


def main():
    N = int(input())
    A = list(map(int, input().split()))

    count = bubble_sort(A)

    print(" ".join(map(str, A)))
    print(count)


if __name__ == "__main__":
    main()


