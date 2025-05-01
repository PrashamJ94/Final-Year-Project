import sys
from math import inf

def main():
    R, G, B, N = map(int, input().split())

    ans = 0
    for x in range(N + 1):
        for y in range(N + 1):
            tmp = N - R * x - G * y
            if tmp >= 0 and tmp % B == 0:
                ans += 1

    print(ans)

def next_int():
    return int(input().strip())

def next_float():
    return float(input().strip())

def next_string():
    return input().strip()

def abs(x):
    return abs(x)

def min(x, y):
    return min(x, y)

def max(x, y):
    return max(x, y)

if __name__ == "__main__":
    main()


