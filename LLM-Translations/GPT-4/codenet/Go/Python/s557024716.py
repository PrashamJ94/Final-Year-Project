
import itertools

def main():
    a, b, c = map(int, input().split())
    k = int(input())

    for pattern in itertools.product(range(4), repeat=k):
        r, g, b = a, b, c
        for i in pattern:
            if i == 1:
                r *= 2
            elif i == 2:
                g *= 2
            elif i == 3:
                b *= 2

        if g > r and b > g:
            print("Yes")
            return

    print("No")

if __name__ == "__main__":
    main()

#
