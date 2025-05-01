import sys

def main():
    A, B, C = map(int, sys.stdin.readline().split())
    if A == B == C:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


