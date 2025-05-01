
from sys import stdout

def main():
    H, W, A, B = map(int, input().split())

    if W < 2 * A or H < 2 * B:
        print(-1)
        return

    for i in range(H):
        for j in range(W):
            if (i < B and j < A) or (i >= B and j >= A):
                stdout.write("0")
            else:
                stdout.write("1")
        stdout.write("\n")
    stdout.flush()

if __name__ == "__main__":
    main()


