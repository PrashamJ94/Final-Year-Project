import sys
from typing import List

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    list = list(map(int, input().strip().split()))
    max = 0
    output = 0
    for i in range(N):
        if max <= list[i]:
            max = list[i]
            output += 1
    print(output)

if __name__ == "__main__":
    main()


