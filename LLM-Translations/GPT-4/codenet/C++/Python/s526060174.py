
from sys import stdin

def main():
    n, m = map(int, input().split())
    x = [0] * 31
    for _ in range(n):
        k, *a = map(int, input().split())
        for j in a:
            x[j] += 1
    ans = 0
    for i in range(1, m+1):
        if x[i] == n:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()

#

