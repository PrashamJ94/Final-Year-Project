
from itertools import product

def main():
    while True:
        try:
            my1, my2, enemy1 = map(int, input().split())
        except EOFError:
            break

        used = [False] * 11
        used[my1] = True
        used[my2] = True
        used[enemy1] = True

        all_cards = 0
        safe = 0

        for i in range(1, 11):
            if not used[i]:
                all_cards += 1
                if my1 + my2 + i <= 20:
                    safe += 1

        if safe * 2 >= all_cards:
            print("YES")
        else:
            print("NO")


def solve(a):
    s = ['d', 'o', 'x']
    for side in range(1, 3):
        for i in range(3):
            if all(a[i][j] == side for j in range(3)) or all(a[j][i] == side for j in range(3)):
                return s[side - 1]
        if all(a[i][i] == side for i in range(3)) or all(a[i][2 - i] == side for i in range(3)):
            return s[side - 1]
    return 'd'


if __name__ == "__main__":
    main()



