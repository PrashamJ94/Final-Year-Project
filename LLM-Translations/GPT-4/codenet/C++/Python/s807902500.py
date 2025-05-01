import sys

def main():
    s = input().strip()
    t = input().strip()
    s += s
    print("Yes" if t in s else "No")

if __name__ == "__main__":
    main()


