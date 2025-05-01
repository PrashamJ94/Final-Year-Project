import sys

def main():
    n = int(input())
    array = list(map(int, input().split()))
    max_val = max(array)
    min_val = min(array)
    print(max_val - min_val)

if __name__ == "__main__":
    main()


