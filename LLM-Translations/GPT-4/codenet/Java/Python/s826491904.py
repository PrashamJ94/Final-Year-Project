import sys

def main():
    N = int(input())
    nums = list(map(int, input().split()))
    max_num = max(nums)
    min_num = min(nums)
    print(max_num - min_num)

if __name__ == "__main__":
    main()


