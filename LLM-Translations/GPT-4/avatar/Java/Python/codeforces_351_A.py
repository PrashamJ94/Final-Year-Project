import sys
from math import floor

def main():
    n = int(input().strip())
    arr = list(map(float, input().strip().split()))
    
    non_int = 0
    sum_before = 0
    sum_after = 0
    
    for num in arr:
        sum_before += num
        if num != floor(num):
            non_int += 1
        sum_after += floor(num)
        
    max_sum = min(n, non_int) + sum_after
    min_sum = max(0, non_int - n) + sum_after
    
    if min_sum > sum_before:
        ans = min_sum - sum_before
    elif max_sum < sum_before:
        ans = sum_before - max_sum
    else:
        x = sum_before - floor(sum_before)
        ans = min(1 - x, x)
        
    print("{:.3f}".format(ans))

if __name__ == '__main__':
    main()


