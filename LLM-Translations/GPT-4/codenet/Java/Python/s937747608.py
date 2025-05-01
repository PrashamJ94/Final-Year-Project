import sys

def main():
    a, b, c, d = map(int, sys.stdin.readline().split())

    if a * b >= c * d:
        print(a * b)
    elif a * b <= c * d:
        print(c * d)

if __name__ == "__main__":
    main()


