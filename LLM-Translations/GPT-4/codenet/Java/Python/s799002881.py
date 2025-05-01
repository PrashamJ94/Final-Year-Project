import sys
import math

def main():
    n, d = map(int, input().split())
    cnt = 0

    for _ in range(n):
        x, y = map(int, input().split())
        if math.sqrt(x*x + y*y) <= d:
            cnt += 1

    print(cnt)

if __name__ == "__main__":
    main()


