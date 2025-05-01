import math
from sys import stdin

n = int(input())
for _ in range(n):
    a = list(map(int, input().split()))
    a.sort()
    if a[2]**2 == a[0]**2 + a[1]**2:
        print("YES")
    else:
        print("NO")
        

