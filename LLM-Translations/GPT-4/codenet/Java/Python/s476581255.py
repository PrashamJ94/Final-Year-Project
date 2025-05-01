
def bubble_sort(arr, n):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in range(n - 1, 0, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                count += 1
                flag = True
    return count


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    count = bubble_sort(arr, n)
    print(" ".join(map(str, arr)))
    print(count)

#
