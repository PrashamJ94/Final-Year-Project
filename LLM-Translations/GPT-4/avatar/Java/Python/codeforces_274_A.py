import sys
from collections import defaultdict

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    count = 0
    set_ = set()
    for i in range(n):
        if arr[i] % k != 0:
            count += 1
            set_.add(arr[i])
        elif arr[i] // k not in set_:
            count += 1
            set_.add(arr[i])
    print(count)

if __name__ == "__main__":
    main()


