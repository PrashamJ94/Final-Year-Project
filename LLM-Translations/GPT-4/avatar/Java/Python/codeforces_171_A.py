
from sys import stdin

def reverse(n):
    if n < 10:
        return n * 10
    t = n
    r = 0
    while t > 0:
        r = (r * 10) + t % 10
        t = t // 10
    return r

def main():
    n, m = map(int, stdin.readline().split())
    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()

##End of Code
