
def main():
    a = input().strip()
    b = input().strip()
    n, m = len(a), len(b)
    ans = float('inf')
    
    for i in range(n - m + 1):
        sum_ = sum(ai != bj for ai, bj in zip(a[i:], b))
        ans = min(ans, sum_)
    
    print(ans)

if __name__ == '__main__':
    main()


