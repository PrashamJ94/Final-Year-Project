import sys

def main():
    input_strs = sys.stdin.readline().split()
    nums = [0] * len(input_strs)
    top = 0
    
    for i in range(len(input_strs)):
        if input_strs[i] == '+':
            top -= 1
            nums[top - 1] = nums[top - 1] + nums[top]
        elif input_strs[i] == '-':
            top -= 1
            nums[top - 1] = nums[top - 1] - nums[top]
        elif input_strs[i] == '*':
            top -= 1
            nums[top - 1] = nums[top - 1] * nums[top]
        else:
            nums[top] = int(input_strs[i])
            top += 1

    print(nums[0])

if __name__ == "__main__":
    main()


