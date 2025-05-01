import sys

def main():
    abc = list(map(int, sys.stdin.readline().split()))
    if abc[0] < abc[1] and abc[1] < abc[2]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


