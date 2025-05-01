import sys
from typing import List

def main():
    n, k = map(int, input().strip().split())
    data = list(map(int, input().strip().split()))
    cnt = [0] * (2 * int(1e5) + 13)
    
    for x in data:
        cnt[x] += 1
        
    a = [x for x in cnt if x > 0]
    a.sort()

    ans = 0
    m = len(a) - k
    for i in range(m):
        ans += a[i]
        
    print(ans)

if __name__ == "__main__":
    main()


