
import sys

def main():
    N, X = map(int, input().split())
    L = list(map(int, input().split()))

    i = 0
    d = 0
    for i in range(N):
        d += L[i]
        if d > X:
            break

    print(i+1)

if __name__ == "__main__":
    main()


#
