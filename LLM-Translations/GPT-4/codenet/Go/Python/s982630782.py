import sys
from typing import Dict, List, Tuple

def read_int() -> int:
    return int(input().strip())

def main():
    m: Dict[int, int] = {}
    N, M = read_int(), read_int()
    for i in map(int, input().split()):
        m[i] = m.get(i, 0) + 1
    for _ in range(M):
        B, C = map(int, input().split())
        m[C] = m.get(C, 0) + B
    ints: List[int] = sorted(m.keys(), reverse=True)
    rest = N
    total = 0
    for i in ints:
        num = m[i]
        if num >= rest:
            total += rest * i
            break
        total += num * i
        rest -= num
    print(total)

if __name__ == '__main__':
    main()


