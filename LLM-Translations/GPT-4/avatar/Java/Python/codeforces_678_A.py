import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    n += 1
    z = 0
    if n % k != 0:
        z = k - n % k
    print(n + z)

if __name__ == "__main__":
    main()


