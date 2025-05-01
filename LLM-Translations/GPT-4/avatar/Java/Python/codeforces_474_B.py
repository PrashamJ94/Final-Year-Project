
from bisect import bisect_left

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    for i in range(1, n):
        arr[i] += arr[i - 1]
    m = int(input())
    q = [int(input()) for _ in range(m)]
    for k in range(m):
        print(fun(arr, q[k]) + 1)

def fun(arr, q):
    res = 0
    i, j = 0, len(arr)
    while i <= j:
        md = i + (j - i) // 2
        if arr[md] == q:
            return md
        elif arr[md] > q:
            res = md
            j = md - 1
        else:
            i = md + 1
    return res

if __name__ == "__main__":
    main()


