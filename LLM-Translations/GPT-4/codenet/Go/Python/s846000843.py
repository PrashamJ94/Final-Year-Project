import sys
from typing import List, Tuple
from math import sqrt, pow

def main() -> None:
    n = int(input().strip())
    aa = list(map(int, input().strip().split()))

    cumsum = cum_sum(aa)
    ans = 2020202020
    for i in range(1, len(cumsum) - 1):
        ans = min(ans, abs(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))

    print(ans)

def abs(a: int) -> int:
    return -a if a < 0 else a

def cum_sum(nums: List[int]) -> List[int]:
    sums = [0]

    for i in range(len(nums)):
        sums.append(sums[i] + nums[i])

    return sums

if __name__ == '__main__':
    main()


