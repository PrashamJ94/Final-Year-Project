import sys

def main():
    a = int(input().strip())
    b = int(input().strip())

    if a * b % 2 != 0:
        print("Odd")
    else:
        print("Even")

if __name__ == "__main__":
    main()


