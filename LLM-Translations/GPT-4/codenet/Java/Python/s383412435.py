import sys
from bisect import bisect_right

def main():
    N = int(input().strip())
    a = list(map(int, input().strip().split()))
    a.sort()
    ans = 0
    
    if N == 1 and a[0] > 1:
        ans = 1
    else:
        j = 0
        while j < N:
            if j == 0 or a[j] != a[j - 1]:
                tmp = 1
                i = j + 1
                while i < N and a[j] == a[i]:
                    tmp += 1
                    i += 1

                if tmp > a[j]:
                    ans += tmp - a[j]
                elif tmp < a[j]:
                    ans += tmp
            
            j += 1
    
    print(ans)

if __name__ == "__main__":
    main()


