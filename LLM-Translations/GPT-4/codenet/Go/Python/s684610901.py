
from itertools import permutations
import sys

def main():
    A, B, C = map(int, input().split())

    if C >= A and C <= B:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

#
