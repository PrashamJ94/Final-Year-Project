import math

def main():
    while True:
        try:
            a, b = map(int, input().split())
            digit = int(math.log10(a+b)) + 1
            print(digit)
        except EOFError:
            break

if __name__ == "__main__":
    main()


