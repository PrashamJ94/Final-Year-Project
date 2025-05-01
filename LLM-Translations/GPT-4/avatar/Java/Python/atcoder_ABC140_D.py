import sys
from itertools import groupby

def main():
    N, K = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()
    
    groups = groupby(S)
    num_groups = sum(1 for _ in groups)

    ans = max(0, num_groups - 2 * K)
    ans = N - ans - 1

    print(ans)

if __name__ == "__main__":
    main()


