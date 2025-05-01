
def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    sum_A = sum(A)
    wa = sum(range(N+1))
    min_value = 1123456789
    
    if sum_A % wa:
        ans = 0
    else:
        shou = sum_A // wa
        sa = [(A[(i+1)%N] - A[i] - shou) for i in range(N)]
        
        ans = 1
        for i in range(N-1):
            if sa[i] <= 0 and not (sa[i] % N):
                ans = 1
            else:
                ans = 0
                break
    
    if ans:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

#


