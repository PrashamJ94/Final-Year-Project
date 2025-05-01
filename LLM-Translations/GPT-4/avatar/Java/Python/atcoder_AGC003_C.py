import heapq
from collections import defaultdict

def main():
    N = int(input())
    nums = list(map(int, input().split()))
    idx_map = defaultdict(int)
    sorted_nums = sorted(nums)

    for i, num in enumerate(nums):
        idx_map[num] = i

    bin = 0
    diff = 0

    for num in sorted_nums:
        idx = idx_map[num]
        if (bin % 2) != (idx % 2):
            diff += 1
        bin += 1
        bin %= 2

    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()


