import sys

def main():
    x, k = map(int, input().split())
    print("Yes" if x % 500 <= k else "No")

if __name__ == "__main__":
    main()


