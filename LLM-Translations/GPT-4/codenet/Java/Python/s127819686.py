import sys

def main():
    a, b = map(int, sys.stdin.readline().split())
    hb = b // 2
    print(a + hb)

if __name__ == "__main__":
    main()


