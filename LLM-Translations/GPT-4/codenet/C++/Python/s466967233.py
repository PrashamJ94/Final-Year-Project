
import sys
from sys import stdin

def main():
    N, K = map(int, input().split())
    A = [0] + list(map(int, input().split()))
    B = [-1] * 200100
    now = 1
    cnt = 0

    j = 1
    B[1] = 0
    while j <= K:
        now = A[now]
        if B[now] == -1:
            B[now] = j
        else:
            cnt = j
            break
        j += 1

    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])
        for _ in range(tmp):
            now = A[now]

    print(now)

if __name__ == "__main__":
    main()

#
