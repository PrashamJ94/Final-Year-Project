import sys
from io import StringIO
import atexit


def main():
    t = 1
    while t > 0:
        solve()
        t -= 1


def solve():
    t = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    prev_winner = 0
    for i in range(len(arr)):
        if arr[i] == 1:
            if prev_winner == 0:
                prev_winner = 2
        
        if prev_winner == 2 or prev_winner == 0:
            if (arr[i] - 1) % 2 == 0:
                print(2)
                prev_winner = 2
            else:
                print(1)
                prev_winner = 1
        else:
            if (arr[i] - 1) % 2 == 0:
                print(1)
                prev_winner = 1
            else:
                print(2)
                prev_winner = 2


if __name__ == "__main__":
    main()


