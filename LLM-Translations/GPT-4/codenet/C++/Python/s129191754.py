
from sys import stdin

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    a.sort()
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    main()

#
