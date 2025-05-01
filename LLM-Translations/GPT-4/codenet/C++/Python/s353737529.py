
def greater_second(f, s):
    return f[1] > s[1]

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def main():
    n = int(input())

    s = ""

    if n == 0:
        print('0')
        return

    while n != 0:
        if n % 2 == 0:
            s += '0'
        else:
            s += '1'

        n -= abs(n % 2)

        n //= -2

    print(s[::-1])

if __name__ == "__main__":
    main()


