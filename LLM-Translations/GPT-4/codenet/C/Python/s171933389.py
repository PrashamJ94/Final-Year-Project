
import sys
from typing import List, Tuple

def get_int4() -> Tuple[int, int, int, int]:
    return tuple(map(int, input().split()))

def fget_array(size: int) -> List[int]:
    return list(map(int, input().split()))

def lower_bound(arr: List[int], r: Tuple[int, int], key: int) -> int:
    low, high = r
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

def main():
    x, y, z, rank = get_int4()
    xrr = fget_array(x)
    yrr = fget_array(y)
    zrr = fget_array(z)
    
    min_sum = min(zrr) + 1
    max_sum = max(zrr)

    pair = [xrr[i] + yrr[j] for i in range(x) for j in range(y)]
    pair.sort()

    min_sum += pair[0]
    max_sum += pair[-1]

    cache = [0] * z
    cnt_map = [0] * z
    ans = [0] * rank

    prev = min_sum
    for r in range(rank, 0, -1):
        low = prev - 1
        high = max_sum + 1
        
        while low + 1 < high:
            mid = (low + high) // 2
            cnt = 0

            for i in range(z):
                pivot = zrr[i]
                r = (cache[i] - 1, len(pair))
                tmp = lower_bound(pair, r, mid - pivot)
                cnt_map[i] = tmp
                cnt += tmp

            if cnt <= (x * y * z) - r:
                cache = cnt_map[:]
                low = mid
            else:
                high = mid
        
        ans[r - 1] = low
        if low == max_sum:
            break
        prev = low

    for i in range(rank):
        print(ans[i] if ans[i] != 0 else max_sum)

if __name__ == "__main__":
    main()


