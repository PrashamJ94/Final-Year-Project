import sys

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    s = [0] * 100010

    for num in nums:
        s[num] += 1

    for i in range(len(s)):
        if s[i] != 0:
            if s[i] % 2 == 0:
                s[i] = 2
            else:
                s[i] = 1

    one = 0
    two = 0

    for count in s:
        if count == 2:
            two += 1
        elif count == 1:
            one += 1

    if two % 2 != 0:
        one -= 1

    print(two + one)

if __name__ == "__main__":
    main()


