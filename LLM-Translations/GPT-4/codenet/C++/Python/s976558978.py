import sys
from math import gcd, pi
from collections import namedtuple
from typing import List

def main():
    a = int(input())
    b = int(input())
    if a < b:
        for _ in range(b):
            print(a, end="")
    else:
        for _ in range(a):
            print(b, end="")

if __name__ == "__main__":
    main()


