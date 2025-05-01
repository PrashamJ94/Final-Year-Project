import math

def main():
    a = int(input())
    b = float(input())
    b_int = int(round(b * 100))
    result = (a * b_int) // 100
    print(result)

if __name__ == "__main__":
    main()


