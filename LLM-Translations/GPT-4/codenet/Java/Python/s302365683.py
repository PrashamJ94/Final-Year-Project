import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    freq = defaultdict(int)
    for num in nums:
        freq[num] += 1
    ans = 0
    for val, num in freq.items():
        if num > val:
            ans += num - val
        else:
            ans += num
    print(ans)

if __name__ == "__main__":
    main()


