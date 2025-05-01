import sys

def main():
    for _ in range(7):
        high, low = map(int, sys.stdin.readline().split())
        sa = high - low
        print(sa)

if __name__ == "__main__":
    main()


