import sys
from itertools import combinations
from collections import Counter

def main():
    n = int(input().strip())
    dic = Counter()
    
    for _ in range(n):
        c = input().strip()[0]
        if c in 'MARCH':
            dic[c] += 1
    
    a = [v for v in dic.values()]
    
    ans = 0
    for comb in combinations(a, 3):
        ans += comb[0] * comb[1] * comb[2]
    
    print(ans)

if __name__ == '__main__':
    main()


