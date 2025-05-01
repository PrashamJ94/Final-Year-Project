import sys
from io import StringIO

def main():
    input = sys.stdin.readline
    n, s = map(int, input().split())
    max_time = 0
    for _ in range(n):
        f, t = map(int, input().split())
        if max_time < f + t:
            max_time = f + t
    print(max(max_time, s))

if __name__ == "__main__":
    main()


