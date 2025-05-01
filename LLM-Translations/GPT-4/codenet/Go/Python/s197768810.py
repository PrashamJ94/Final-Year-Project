import sys

def read_int():
    return int(input())

def read_float64():
    return float(input())

def read_string():
    return input()

def main():
    n, m = read_int(), read_int()
    a = [0] * n
    total = 0
    for i in range(m):
        a[i] = read_int()
        total += a[i]
    if total > n:
        print("-1")
        return

    print(n - total)

if __name__ == "__main__":
    main()


