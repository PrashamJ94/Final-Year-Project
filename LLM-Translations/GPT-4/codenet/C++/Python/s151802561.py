def selection_sort(arr):
    n = len(arr)
    sw = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if arr[j] < arr[mini]:
                mini = j
        if i != mini:
            arr[i], arr[mini] = arr[mini], arr[i]
            sw += 1
    return sw

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    sw = selection_sort(arr)

    print(" ".join(map(str, arr)))
    print(sw)

if __name__ == '__main__':
    main()


