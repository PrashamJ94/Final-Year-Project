import sys

def main():
    m, n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    x_max = max_int(x, a)
    y_min = min_int(y, b)
    check_war(x_max, y_min)

def max_int(x, a):
    bignum = x
    for i in a:
        bignum = max(bignum, i)
    return bignum

def min_int(y, b):
    smallnum = y
    for i in b:
        smallnum = min(smallnum, i)
    return smallnum

def check_war(a, b):
    if a >= b:
        print("War")
    else:
        print("No War")

if __name__ == '__main__':
    main()


