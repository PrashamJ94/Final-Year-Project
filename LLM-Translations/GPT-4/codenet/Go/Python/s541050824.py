import sys
from typing import List, Tuple

def read_line() -> str:
    return sys.stdin.readline().strip()

def read_int() -> int:
    return int(read_line())

def read_int_tuple() -> Tuple[int]:
    return tuple(map(int, read_line().split()))

def read_int_list() -> List[int]:
    return list(map(int, read_line().split()))

def div_up(x: int, y: int) -> int:
    return (x + y - 1) // y

def solve() -> None:
    N = read_int()
    T, A = [0] * N, [0] * N
    for i in range(N):
        T[i], A[i] = read_int_tuple()
    t, a = T[0], A[0]
    for i in range(1, N):
        r = max(div_up(t, T[i]), div_up(a, A[i]))
        t, a = T[i] * r, A[i] * r
    print(t + a)

def main() -> None:
    solve()

if __name__ == "__main__":
    main()


