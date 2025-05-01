
from sys import stdin

def main():
    m = [10, 50, 100, 500]
    first = True
    lines = stdin.readlines()
    idx = 0

    while idx < len(lines):
        money = int(lines[idx].strip())
        idx += 1
        if money == 0:
            break

        if not first:
            print()

        first = False
        sum_ = 0
        num = [int(x) for x in lines[idx].strip().split()]
        idx += 1
        for i in range(4):
            sum_ += num[i] * m[i]

        change = sum_ - money
        for i in range(3, -1, -1):
            if change // m[i]:
                num[i] = num[i] - change // m[i]
                change %= m[i]

        for i in range(4):
            if num[i] > 0:
                print(m[i], num[i])

if __name__ == "__main__":
    main()


