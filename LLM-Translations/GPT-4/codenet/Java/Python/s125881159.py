import sys

def main():
    n = int(input().strip())
    d = 0
    nums = list(map(int, input().strip().split()))
    for num in nums:
        d += num % 2
    print("YES" if d % 2 == 0 else "NO")

if __name__ == "__main__":
    main()


