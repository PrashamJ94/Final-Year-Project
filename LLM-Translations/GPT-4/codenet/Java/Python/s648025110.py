import sys

def main():
    n = int(input().strip())
    h = list(map(int, input().strip().split()))
    
    ans = 0
    out = 0

    for i in range(len(h)):
        if out < h[i]:
            ans += h[i] - out
            out = h[i]
        else:
            out = h[i]

    print(ans)

if __name__ == "__main__":
    main()


