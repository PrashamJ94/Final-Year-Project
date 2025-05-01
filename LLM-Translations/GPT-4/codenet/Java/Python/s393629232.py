import sys

def main():
    n = int(input())
    maxv = -sys.maxsize
    minv = int(input())
    for i in range(1, n):
        ri = int(input())
        maxv = max(maxv, ri - minv)
        minv = min(minv, ri)
    print(maxv)

if __name__ == "__main__":
    main()


