import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    
    ans = 0
    a_prev = 0
    for _ in range(n):
        a = int(input().strip())
        if a > _ or a > a_prev + 1:
            print(-1)
            return
        elif a == a_prev + 1:
            ans += 1
        else:
            ans += a
        a_prev = a
    print(ans)

if __name__ == "__main__":
    main()


