import sys
from itertools import combinations

def main():
    source = input().strip()

    if len(source) > 10 or len(source) < 1:
        return -1

    max_i = int(2**(len(source) - 1))

    total_sum = 0

    for i in range(max_i):
        plus = bin(i)[2:].zfill(len(source) - 1)
        indices = [index for index, value in enumerate(plus) if value == '1']
        indices.append(len(source))
        start = 0
        for index in indices:
            total_sum += float(source[start:index])
            start = index

    print("{:.0f}".format(total_sum))

if __name__ == "__main__":
    main()


