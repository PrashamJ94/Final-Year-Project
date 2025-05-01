import sys

def main():

    X, t = map(int, sys.stdin.readline().split())

    if X >= t:
        print(X - t)
    elif X < t:
        print(0)

if __name__ == "__main__":
    main()


