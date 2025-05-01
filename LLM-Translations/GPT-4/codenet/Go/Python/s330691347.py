import sys
from typing import List, Tuple

class Data:
    def __init__(self, x: str):
        self.x = x

def main() -> None:
    input = sys.stdin.readline
    N, L = map(int, input().strip().split())
    s = [Data(input().strip()) for _ in range(N)]

    s.sort(key=lambda data: data.x)

    ans = ""
    for i in range(N):
        ans += s[i].x
    print(ans)

if __name__ == '__main__':
    main()


