import sys
from typing import List, Tuple

def main():
    h, w, k = map(int, input().split())
    colorMtr = [input() for _ in range(h)]

    hPattern = pow(2, h)
    wPattern = pow(2, w)

    ans = 0

    for i in range(hPattern):
        for j in range(wPattern):
            if judge(i, j, h, w, k, colorMtr):
                ans += 1

    print(ans)


def judge(hPattern: int, wPattern: int, h: int, w: int, k: int, colorMtr: List[str]) -> bool:

    hBitArr = [0] * h
    wBitArr = [0] * w

    for i in range(h):
        if (hPattern >> i) & 1 == 1:
            hBitArr[i] = 1

    for i in range(w):
        if (wPattern >> i) & 1 == 1:
            wBitArr[i] = 1

    black = 0

    for i in range(h):
        for j in range(w):
            if hBitArr[i] == 1 or wBitArr[j] == 1:
                continue

            if colorMtr[i][j] == "#":
                black += 1

    if black == k:
        return True
    else:
        return False

if __name__ == "__main__":
    main()


