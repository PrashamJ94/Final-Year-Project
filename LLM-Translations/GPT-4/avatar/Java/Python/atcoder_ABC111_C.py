import sys
from collections import Counter

def main():
    n = int(sys.stdin.readline())
    v = list(map(int, sys.stdin.readline().split()))
    vo = [0] * 100010
    ve = [0] * 100010
    vt = [0] * 100010
    
    for i in range(n):
        vt[v[i]] += 1
        if i % 2 == 0:
            ve[v[i]] += 1
        else:
            vo[v[i]] += 1
            
    vo_counter = Counter(vo).most_common()
    ve_counter = Counter(ve).most_common()
    vt_counter = Counter(vt).most_common()
    
    ans = 0
    if vo_counter[0][1] + ve_counter[0][1] == vt_counter[0][1]:
        ans = min(n - vo_counter[0][1] - ve_counter[1][1], n - vo_counter[1][1] - ve_counter[0][1])
    else:
        ans = n - vo_counter[0][1] - ve_counter[0][1]
        
    print(ans)

if __name__ == "__main__":
    main()


