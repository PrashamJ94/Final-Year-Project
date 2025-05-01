import sys
import math

def main():
    N = input().strip()
    b = [int(c) for c in N]
    n = sum(b)
    m = int(N)
    if m % n == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


