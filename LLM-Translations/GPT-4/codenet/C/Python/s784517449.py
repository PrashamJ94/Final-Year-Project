def binary_search(arr, key):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if key == arr[mid]:
            return 1
        if key > arr[mid]:
            left = mid + 1
        else:
            right = mid
    return 0


def main():
    n = int(input())
    arr = [int(input()) for _ in range(n)]
    q = int(input())
    sum = 0
    for _ in range(q):
        k = int(input())
        if binary_search(arr, k):
            sum += 1
    print(sum)


if __name__ == "__main__":
    main()


