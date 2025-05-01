
import sys

def main():
    a, b = map(int, sys.stdin.readline().split())
    
    if a > 0:
        print("Positive")
    elif b >= 0:
        print("Zero")
    elif (b - a + 1) % 2 == 0:
        print("Positive")
    else:
        print("Negative")

if __name__ == "__main__":
    main()


