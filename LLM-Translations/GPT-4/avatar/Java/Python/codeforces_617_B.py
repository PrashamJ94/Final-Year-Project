import sys
from typing import List

def main():
    n = int(input().strip())
    arr = []

    data = list(map(int, input().strip().split()))

    for i in range(n):
        if data[i] == 1:
            arr.append(i)

    if not arr:
        print(0)
    else:
        result = 1
        for i in range(1, len(arr)):
            result *= arr[i] - arr[i - 1]
        print(result)

if __name__ == "__main__":
    main()


