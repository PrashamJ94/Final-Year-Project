import sys

def main():
    n = int(input().strip())
    binary_str = bin(n)[2:]
    count = binary_str.count('1')
    print(count)

if __name__ == "__main__":
    main()


