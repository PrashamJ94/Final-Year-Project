def binary_search(arr, key):
    left = 0
    right = len(arr)
    
    while left < right:
        mid = (left + right) // 2
        if arr[mid] == key:
            return 1
        elif key < arr[mid]:
            right = mid
        else:
            left = mid + 1
            
    return 0


def main():
    n = int(input())
    S = list(map(int, input().split()))
    
    q = int(input())
    T = list(map(int, input().split()))
    
    c = 0
    for t in T:
        if binary_search(S, t) == 1:
            c += 1
            
    print(c)


if __name__ == "__main__":
    main()


