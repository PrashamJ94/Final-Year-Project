import sys
from io import StringIO
import atexit

def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    ans = 0
    MOD = 1000000007
    sum_ = A[N-1]
    for i in range(N - 2, -1, -1):
        ans += (sum_ * A[i]) % MOD
        ans %= MOD
        sum_ += A[i]
        sum_ %= MOD
    print(ans)

if __name__ == '__main__':
    main()


