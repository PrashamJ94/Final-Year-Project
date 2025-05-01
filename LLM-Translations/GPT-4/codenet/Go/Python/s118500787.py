import sys

def main():
    S, T = input().strip(), input().strip()
    max_c = 0
    for i in range(len(S) - len(T) + 1):
        c = 0
        for j in range(len(T)):
            if S[i + j] == T[j]:
                c += 1
        max_c = max(max_c, c)
    print(len(T) - max_c)

if __name__ == "__main__":
    main()


