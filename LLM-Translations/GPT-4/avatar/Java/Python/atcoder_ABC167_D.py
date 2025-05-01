import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = [int(a) - 1 for a in input().split()]
    
    used = set()
    idx = defaultdict(int)
    pos = defaultdict(int)
    next_pos, cur = 0, 0
    
    while next_pos not in used:
        used.add(next_pos)
        idx[next_pos] = cur
        pos[cur] = next_pos
        next_pos = A[next_pos]
        cur += 1
    
    a = cur - idx[next_pos]
    b = idx[next_pos]
    ans = (10000 * a + K - b) % a + b
    if b > K:
        ans = K
    print(pos[ans] + 1)

if __name__ == '__main__':
    main()


