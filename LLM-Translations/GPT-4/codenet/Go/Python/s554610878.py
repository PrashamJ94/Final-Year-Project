
import sys
from math import pow, fabs, floor

def main():
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    s = input().strip()
    index = -1
    for i, day in enumerate(week):
        if s == day:
            index = i
            break

    print(7 - index)

def getInt():
    return int(input().strip())

def getString():
    return input().strip()

def abs(a):
    return int(fabs(a))

def pow(p, q):
    return int(pow(p, q))

def min(*nums):
    if len(nums) == 0:
        raise ValueError("Function min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

def max(*nums):
    if len(nums) == 0:
        raise ValueError("Function max() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

def strSearch(a, b):
    return b in a

def printIntArray(array):
    print(", ".join(map(str, array)))

def calcMod(x):
    return x % (int(1e9) + 7)

if __name__ == "__main__":
    main()


