import math

def gcd(a, b):
    return math.gcd(a, b)

def main():
    n = int(input())
    ans = int(input())

    for i in range(1, n):
        a = int(input())
        ans = gcd(ans, a)

    print(ans)

if __name__ == "__main__":
    main()


