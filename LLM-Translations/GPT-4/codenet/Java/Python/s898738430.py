import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    ans = 0
    for i in range(1, n-1):
        if a[i] != min(a[i-1], min(a[i], a[i+1])) and a[i] != max(a[i-1], max(a[i], a[i+1])):
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()


