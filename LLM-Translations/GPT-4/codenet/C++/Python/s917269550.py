import sys
from math import fabs

x, y = map(int, sys.stdin.readline().split())

if fabs(x - y) <= 1:
    print("Brown")
else:
    print("Alice")


