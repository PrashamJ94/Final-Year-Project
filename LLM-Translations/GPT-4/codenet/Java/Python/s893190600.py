import sys
from collections import defaultdict

def main():
    H, W = map(int, input().split())
    C = [input().strip() for _ in range(H)]
    
    if H == 1 and W == 1:
        print("No")
        return

    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if C[i - 1][j - 1] == '#' and C[i - 2][j - 1] != '#' and C[i][j - 1] != '#' and C[i - 1][j - 2] != '#' and C[i - 1][j] != '#':
                print("No")
                return

    print("Yes")

if __name__ == "__main__":
    main()


