
import sys

def max_left(n):
    return n - 2 if n > 2 else 0

def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        print(max_left(n))

if __name__ == "__main__":
    main()

##End of Code
