
import sys

def main():
    a, b = map(int, sys.stdin.readline().split())
    if a % 2 == 0 or b % 2 == 0:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()


