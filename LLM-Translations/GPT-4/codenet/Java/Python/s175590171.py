import sys
from io import StringIO

def main():
    input = sys.stdin.buffer.readline
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    sum = 0
    count = 0
    for i in range(n - 1):
        sum += a[i]
        if a[i + 1] <= 2 * sum:
            count += 1
        else:
            count = 0
    print(count + 1)

if __name__ == '__main__':
    main()


