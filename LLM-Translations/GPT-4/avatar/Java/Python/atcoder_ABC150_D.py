
from math import gcd
from functools import reduce

def main():
    n, m = map(int, input().split())
    a = list(map(lambda x: int(x) // 2, input().split()))
    
    def lcm(x, y):
        return x * y // gcd(x, y)
    
    lcd = reduce(lcm, a)
    
    if lcd > m:
        print(0)
        return
    
    for i in range(n):
        if (lcd // a[i]) % 2 == 0:
            print(0)
            return
    
    print((m // lcd + 1) // 2)

if __name__ == "__main__":
    main()


