import sys
from sys import stdin
from math import gcd
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    DEVISOR = 1000000000+7

    ans = 0
    for i in range(k, n+2):
        max_value = i*(2*n-i+1)//2
        min_value = i*(i-1)//2
        ans += (max_value - min_value + 1) % DEVISOR
    
    print(ans % DEVISOR)

if __name__ == "__main__":
    main()


