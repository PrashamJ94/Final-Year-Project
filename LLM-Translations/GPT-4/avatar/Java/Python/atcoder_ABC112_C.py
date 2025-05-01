import sys
from itertools import product

def main():
    n = int(input())
    data = [tuple(map(int, input().split())) for _ in range(n)]

    for cx, cy in product(range(101), repeat=2):
        heights = [abs(x - cx) + abs(y - cy) + h for x, y, h in data if h > 0]
        ch = min(heights)
        if all(h == max(ch - abs(x - cx) - abs(y - cy), 0) for x, y, h in data):
            print(cx, cy, ch)
            break

if __name__ == '__main__':
    main()


