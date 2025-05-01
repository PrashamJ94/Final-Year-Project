
from sys import stdin

def main():
    N = int(input().strip())
    P = list(map(int, input().strip().split()))
    mem = [0] * (N + 1)
    for i in range(1, N + 1):
        mem[P[i - 1]] = i

    maxcnt = 1
    cnt = 1
    for i in range(1, N):
        if mem[i] < mem[i + 1]:
            cnt += 1
        else:
            maxcnt = max(maxcnt, cnt)
            cnt = 1
        if i == N - 1:
            maxcnt = max(maxcnt, cnt)

    print(N - maxcnt)

if __name__ == "__main__":
    main()


