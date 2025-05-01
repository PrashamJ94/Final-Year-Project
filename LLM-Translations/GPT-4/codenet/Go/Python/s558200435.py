def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]

    b = []
    for v in a:
        x = binary_search(b, v)
        if x == len(b):
            b.append(v)
        else:
            b[x] = v

    print(len(b))

def binary_search(arr, target):
    low, high = 0, len(arr)

    while low < high:
        mid = (low + high) // 2
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid

    return low

if __name__ == "__main__":
    main()


