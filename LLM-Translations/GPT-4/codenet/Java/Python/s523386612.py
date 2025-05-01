
import sys
from collections import defaultdict

def main():
    t = int(input().strip())
    count = defaultdict(int)
    nums = list(map(int, input().strip().split()))

    for i in range(t - 1):
        count[nums[i]] += 1

    for i in range(1, t + 1):
        print(count[i])

if __name__ == '__main__':
    main()


#
