def insertion_sort(arr):
    for j in range(1, len(arr)):
        key = arr[j]
        i = j - 1
        while i >= 0 and arr[i] > key:
            arr[i + 1] = arr[i]
            i -= 1
        arr[i + 1] = key
    return arr

def main():
    len_arr = int(input())
    arr = list(map(int, input().split()))

    for j in range(1, len(arr)):
        print(" ".join(map(str, arr)))
        insertion_sort(arr)

    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    main()


