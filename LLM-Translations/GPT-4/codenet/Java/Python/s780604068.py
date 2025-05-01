import sys

def main():
    N = int(input().strip())
    map_values = list(map(int, input().strip().split()))
    map_values.sort()

    max_sum = 0
    for i in range(0, N * 2, 2):
        max_sum += min(map_values[i], map_values[i + 1])

    print(max_sum)

if __name__ == "__main__":
    main()


