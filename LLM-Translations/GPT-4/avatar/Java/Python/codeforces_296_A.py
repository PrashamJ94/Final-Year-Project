
from sys import stdin

def main():
    n = int(input().strip())
    array = [0] * 1001

    for index in map(int, input().strip().split()):
        array[index] += 1

    count_max = max(array)

    if n % 2 == 0:
        if count_max <= n // 2:
            print("YES")
        else:
            print("NO")
    else:
        if count_max <= n // 2 + 1:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()


