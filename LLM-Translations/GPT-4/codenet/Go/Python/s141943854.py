import sys

def check(e):
    if e:
        sys.exit(f"error: {e}")

def main():
    sage = input()

    if sage == "1":
        print("Hello World")
    elif sage == "2":
        total = 0
        for i in range(2):
            try:
                num = int(input())
            except ValueError as e:
                check(e)
            total += num
        print(total)

if __name__ == "__main__":
    main()


