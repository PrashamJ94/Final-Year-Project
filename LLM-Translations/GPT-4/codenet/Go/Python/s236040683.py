import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    n = defaultdict(list)

    for _ in range(M):
        from_, to = map(lambda x: int(x) - 1, input().split())
        n[from_].append(to)
        n[to].append(from_)

    for i in range(N):
        print(len(n[i]))

if __name__ == "__main__":
    main()


