import sys

def read():
    return list(map(int, sys.stdin.readline().split()))

def main():
    n = int(input())
    a = read()
    a.sort()
    q = []
    tot = 0
    i = 0
    while i < n:
        if a[i] == a[i + 1]:
            q.append(a[i])
            tot += 1
            i += 1
        i += 1
    print(q[tot - 1] * q[tot - 2])

if __name__ == "__main__":
    main()


