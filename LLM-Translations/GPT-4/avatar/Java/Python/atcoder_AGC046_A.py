
from sys import stdin
from math import gcd

def main():
    x = int(input().strip())
    count = 0
    tmp = x
    x = 0
    while x != 360:
        x = x + tmp
        if x > 360:
            x = x - 360
        count += 1
    print(count)

if __name__ == '__main__':
    main()


