import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    pre = [0] * (n + 1)
    last = [0] * (n + 1)
    sumpre = 0
    sumlast = 0
    
    for i in range(n - 1):
        sumpre += a[i]
        pre[i] = sumpre
        
    for i in range(n - 1, 0, -1):
        sumlast += a[i]
        last[i] = sumlast
        
    d = 1 << 60
    for i in range(n - 1):
        d = min(d, abs(pre[i] - last[i + 1]))
        
    print(d)

if __name__ == "__main__":
    main()


