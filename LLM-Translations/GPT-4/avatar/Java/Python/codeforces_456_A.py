
from sys import stdin

def main():
    n = int(input())
    ab = [tuple(map(int, input().split())) for _ in range(n)]
    ab.sort()
    max_b = -1
    happy_alex = False

    for a, b in ab:
        if b > max_b:
            max_b = b
        elif b < max_b:
            happy_alex = True
            break

    if happy_alex:
        print("Happy Alex")
    else:
        print("Poor Alex")

if __name__ == "__main__":
    main()


