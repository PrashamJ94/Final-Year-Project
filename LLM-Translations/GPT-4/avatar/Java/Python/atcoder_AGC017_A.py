import math
from functools import reduce
from operator import mul

def nCr(n, r):
    if n < 1 or r < 0 or n < r: 
        return 0
    if r == 0 or r == n: 
        return 1
    return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))

def main():
    n, p = map(int, input().split())
    k0 = 0
    k1 = 0
    data = list(map(int, input().split()))
    
    for x in data:
        if x % 2 == 1:
            k1 += 1
        else:
            k0 += 1

    ans = 1 << k0
    
    if p == 0:
        add = sum(nCr(k1, i) for i in range(0, k1 + 1, 2))
        ans *= add
        print(ans)
    else:
        add = sum(nCr(k1, i) for i in range(1, k1 + 1, 2))
        ans *= add
        print(ans)

if __name__ == "__main__":
    main()


