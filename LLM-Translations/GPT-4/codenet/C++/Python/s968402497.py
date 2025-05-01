
from sys import stdin

def main():
    tc, n, m = map(int, input().split())
    fl = 0
    if n > m:
        n, m = m, n
    for i in range(1, m + 1):
        if i * tc >= n and i * tc <= m:
            print("OK")
            fl = 1
            break
    if fl == 0:
        print("NG")

if __name__ == "__main__":
    main()


