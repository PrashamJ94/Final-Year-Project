
from sys import stdin
from itertools import permutations

def main():
    a, b, c, d = map(int, stdin.readline().split())
    
    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = sorted([a, b, c, d])
        print(l[2] - l[1])

if __name__ == "__main__":
    main()


