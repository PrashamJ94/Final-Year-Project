import sys

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    min_val = sys.maxsize
    count = 0
    total = 0
    for i in range(N):
        if A[i] < 0:
            count += 1
        min_val = min(min_val, abs(A[i]))
        total += abs(A[i])

    if count % 2 == 0:
        print(total)
    else:
        print(total - min_val * 2)

if __name__ == "__main__":
    main()


