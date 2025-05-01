
from sys import stdin

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    curr = 0
    for i in range(n):
        if a[i] == curr + 1:
            curr += 1

    if curr > 0:
        print(n - curr)
    else:
        print(-1)

if __name__ == '__main__':
    main()


