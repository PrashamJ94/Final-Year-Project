import sys
from typing import List, Any

def main():
    n = int(input().strip())
    list_ = [int(x) for x in input().strip().split()]
    list_.sort()
    c = 1
    for i in range(n):
        if list_[i] >= c:
            c += 1
    print(c)

def debug(*obj: Any) -> None:
    print(*obj, file=sys.stderr)

if __name__ == '__main__':
    main()


