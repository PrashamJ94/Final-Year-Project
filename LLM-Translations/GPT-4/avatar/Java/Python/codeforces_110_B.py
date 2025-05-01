import sys

def main():
    n = int(input())
    p = 97
    c = [''] * n

    for i in range(4):
        for j in range(i, n, 4):
            c[j] = chr(p)
        p += 1

    for i in range(n):
        sys.stdout.write(c[i])

if __name__ == "__main__":
    main()


