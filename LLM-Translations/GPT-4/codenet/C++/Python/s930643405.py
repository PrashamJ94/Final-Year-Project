
from sys import stdin

def main():
    n, k = map(int, input().split())
    broken = [False] * 10
    for _ in range(k):
        a = int(input())
        broken[a] = True

    while True:
        x = n
        hantei = True
        while x:
            if broken[x % 10]:
                hantei = False
                break
            x //= 10

        if hantei:
            print(n)
            break

        n += 1

if __name__ == "__main__":
    main()

#
