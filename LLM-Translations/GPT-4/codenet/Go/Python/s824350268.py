import sys
import math

def main():
    N = int(input().strip())
    sqrtN = int(math.sqrt(N))

    min_val = N
    for i in range(1, sqrtN+1):
        if N % i != 0:
            continue

        num = i + (N//i) - 2
        if num < min_val:
            min_val = num

    print(min_val)

main()


