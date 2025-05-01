
from itertools import product

def main():
    n, m = map(int, input().split())
    sc = [tuple(map(int, input().split())) for _ in range(m)]

    for i in range(1000):
        s = str(i)
        if len(s) != n:
            continue

        valid = True
        for (pos, digit) in sc:
            if s[pos - 1] != str(digit):
                valid = False
                break

        if valid:
            print(i)
            return

    print(-1)

if __name__ == "__main__":
    main()


