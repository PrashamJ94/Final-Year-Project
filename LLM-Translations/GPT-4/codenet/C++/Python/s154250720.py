import sys
from bisect import bisect_left

def main():
    n = int(input().strip())
    maps = list(map(int, input().strip().split()))
    num = maps.copy()
    maps.sort()
    m = n // 2
    for i in range(n):
        if num[i] <= maps[m - 1]:
            print(maps[m])
        else:
            print(maps[m - 1])

if __name__ == "__main__":
    main()


