
from sys import stdin


def main():
    n, k = map(int, stdin.readline().split())
    logs_length = list(map(int, stdin.readline().split()))

    min_val, max_val = 1, int(1e9) + 1000

    while min_val < max_val:
        mid = (min_val + max_val) // 2
        if nei(mid, logs_length, k):
            max_val = mid
        else:
            min_val = mid + 1

    print(min_val)


def nei(mid, logs_length, k):
    for log in logs_length:
        k -= (log + mid - 1) // mid - 1

    return k >= 0


if __name__ == "__main__":
    main()


##End of Code
