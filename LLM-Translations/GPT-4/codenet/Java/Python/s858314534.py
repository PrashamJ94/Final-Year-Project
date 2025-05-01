import sys

def main():
    A, B, T = map(int, sys.stdin.readline().split())

    result = (T // A) * B
    print(result)

if __name__ == '__main__':
    main()


