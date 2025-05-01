def solve(i, m, n, A):
    if i > n:
        return False
    elif m < 0:
        return False
    elif m == 0 or m - A[i + 1] == 0:
        return True
    else:
        return solve(i + 1, m, n, A) or solve(i + 1, m - A[i], n, A)

def main():
    n = int(input())
    A = list(map(int, input().split()))

    q = int(input())
    for _ in range(q):
        M = int(input())
        if solve(-1, M, n, A):
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()


