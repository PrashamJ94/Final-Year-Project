import sys

def main():
    n = int(input().strip())
    lr = []
    for _ in range(n):
        l, r = map(int, input().strip().split())
        lr.append((l, r))
    sum = 0
    for l, r in lr:
        sum += r - l + 1
    print(sum)

if __name__ == "__main__":
    main()


