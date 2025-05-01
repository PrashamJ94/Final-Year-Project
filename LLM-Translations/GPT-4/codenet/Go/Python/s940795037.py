import sys
from typing import List, Dict

def main():
    n = int(input().strip())
    ans = 0.0
    nums = list(map(int, input().strip().split()))
    for i in range(n):
        tmp = 1 / float(nums[i])
        ans += tmp
    print(1/ans)

if __name__ == "__main__":
    main()


