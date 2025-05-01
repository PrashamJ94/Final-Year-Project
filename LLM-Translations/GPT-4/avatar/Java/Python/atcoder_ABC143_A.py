import sys

def main():
    a, b = map(int, sys.stdin.readline().strip().split())
    c = a - b * 2
    if c < 0:
        c = 0
    print(c)

if __name__ == "__main__":
    main()


