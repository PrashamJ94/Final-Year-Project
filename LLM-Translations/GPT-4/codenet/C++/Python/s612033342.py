import itertools

def pow2(a):
    ret = 1
    for i in range(a):
        ret *= 2
    return ret

def count(hw, a, b):
    sum = 0
    for i in range(len(hw)):
        for j in range(len(hw[0])):
            if (a >> i) & 1 and (b >> j) & 1 and hw[i][j] == 1:
                sum += 1
    return sum

def main():
    h, w, k = map(int, input().split())
    hw = []
    for i in range(h):
        row = []
        for c in input():
            if c == '#':
                row.append(1)
            else:
                row.append(0)
        hw.append(row)

    sum = 0
    for i in range(pow2(h)):
        for j in range(pow2(w)):
            if count(hw, i, j) == k:
                sum += 1
    print(sum)

if __name__ == "__main__":
    main()


