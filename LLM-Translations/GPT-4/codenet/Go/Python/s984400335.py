def min(nums):
    min_value = nums[0]
    for v in nums:
        if v < min_value:
            min_value = v
    return min_value

n, a, b = map(int, input().split())

print(min([n * a, b]))


