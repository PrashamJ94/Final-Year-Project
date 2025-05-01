
from sys import stdin
from typing import List

def read_int() -> int:
    return int(stdin.readline().strip())

def read_ints() -> List[int]:
    return list(map(int, stdin.readline().strip().split()))

def main() -> None:
    N, K = read_int(), read_int()
    As = read_ints()
    Fs = read_ints()

    As.sort()
    Fs.sort(reverse=True)
    scores = [As[i] * Fs[i] for i in range(N)]
    scores.sort(reverse=True)

    ok = scores[0]
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2

        is_OK = True
        k = K
        for i in range(N):
            if As[i] * Fs[i] > mid:
                k -= As[i] - mid // Fs[i]
            if k < 0:
                is_OK = False
                break

        if is_OK:
            ok = mid
        else:
            ng = mid

    print(ok)

if __name__ == '__main__':
    main()


