import sys

def main():
    h, n = map(int, input().split())
    a = sum(map(int, input().split()))

    if h > a:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()


