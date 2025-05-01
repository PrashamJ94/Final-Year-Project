def bubble_sort(arr):
    n = len(arr)
    d = 0
    for i in range(n):
        for j in range(n-1, i, -1):
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
                d += 1
    return d

def main():
    n = int(input())
    a = list(map(int, input().split()))
    d = bubble_sort(a)
    print(" ".join(map(str, a)))
    print(d)

if __name__ == "__main__":
    main()


