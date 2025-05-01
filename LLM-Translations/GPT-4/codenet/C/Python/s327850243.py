import sys

def main():
    m, n = map(int, input().split())
    A = []
    B = []
    S = [0] * m

    for i in range(m):
        A.append(list(map(int, input().split())))

    for i in range(n):
        B.append(int(input()))

    for i in range(m):
        for j in range(n):
            S[i] = S[i] + A[i][j] * B[j]

    for i in range(m):
        print(S[i])

if __name__ == "__main__":
    main()


