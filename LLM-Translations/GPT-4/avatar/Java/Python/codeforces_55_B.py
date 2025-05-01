import sys
from itertools import permutations

def min_expression(arr, ops):
    if len(arr) == 1:
        return arr[0]

    min_val = sys.maxsize
    for i in range(len(arr) - 1):
        for op in ops:
            new_arr = arr[:i] + arr[i+2:]
            if op == '+':
                new_arr.insert(i, arr[i] + arr[i+1])
            else:
                new_arr.insert(i, arr[i] * arr[i+1])
            min_val = min(min_val, min_expression(new_arr, ops))
    return min_val

def main():
    arr = [int(input()) for _ in range(4)]
    ops = [input() for _ in range(3)]

    min_val = sys.maxsize
    for perm in permutations(ops):
        min_val = min(min_val, min_expression(arr, perm))

    print(min_val)

if __name__ == "__main__":
    main()


