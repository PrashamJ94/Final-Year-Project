
import sys

def main():
    S = input().strip()
    if S.startswith("YAKI"):
        print("Yes")
    else:
        print("No")

def min(a, b):
    return b if a > b else a

def max(a, b):
    return a if a > b else b

if __name__ == "__main__":
    main()


#
