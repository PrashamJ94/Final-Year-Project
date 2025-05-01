import sys
from collections import defaultdict

def main():
    n = int(input())
    data = list(map(int, input().split()))
    freq_map = defaultdict(int)
    
    for num in data:
        freq_map[num] += 1
        
    ans = 0
    for key in freq_map:
        if freq_map[key] % 2 == 1:
            ans += 1
            
    print(ans)

if __name__ == "__main__":
    main()
#
