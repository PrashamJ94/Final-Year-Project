import sys
from collections import OrderedDict

def main():
    N = int(input())
    A = list(map(int, input().split()))
    idorder = OrderedDict()

    for i in range(N):
        idorder[A[i]] = i + 1

    for i in range(1, N + 1):
        sys.stdout.write(str(idorder.get(i)) + " ")

if __name__ == "__main__":
    main()


