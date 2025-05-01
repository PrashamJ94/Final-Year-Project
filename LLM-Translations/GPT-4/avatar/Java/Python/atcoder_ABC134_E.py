import sys
from bisect import bisect_left
from collections import defaultdict

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    map = defaultdict(int)
    
    for num in nums:
        key = bisect_left(sorted(map.keys()), num)
        if key == 0:
            map[num] += 1
        else:
            keys = sorted(map.keys())
            key = keys[key-1]
            val = map[key]
            if val == 1:
                del map[key]
            else:
                map[key] -= 1
            map[num] += 1
            
    ans = 0
    for key in map:
        ans += map[key]
        
    print(ans)

main()


