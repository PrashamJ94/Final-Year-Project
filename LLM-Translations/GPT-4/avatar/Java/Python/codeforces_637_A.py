import sys
from collections import defaultdict

def main():
    n = int(input())
    ara = list(map(int, input().split()))
    counter = defaultdict(int)
    
    for v in ara:
        counter[v] += 1
    
    max_count = max(counter.values())
    mm = defaultdict(int)
    
    for i in range(n):
        mm[ara[i]] += 1
        if mm[ara[i]] == max_count:
            print(ara[i])
            break

if __name__ == "__main__":
    main()


