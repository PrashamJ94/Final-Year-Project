import sys
from sys import stdin

def main():
    N, X = map(int, input().split())
    m = list(map(int, input().split()))
    X -= m[0]
    min_val = m[0]
    for i in range(1, N):
        X -= m[i]
        if m[i] < min_val:
            min_val = m[i]
    print(N + X // min_val)

main()

