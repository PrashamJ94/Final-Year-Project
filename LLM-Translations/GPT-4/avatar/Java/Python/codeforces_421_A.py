import sys
from collections import deque

def main():
    n, a, b = map(int, input().split())
    list1 = list(map(int, input().split()))
    list2 = list(map(int, input().split()))

    for i in range(n):
        if (i + 1) in list1:
            print(1, end=" ")
        else:
            print(2, end=" ")
    print()

if __name__ == "__main__":
    main()


