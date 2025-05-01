import sys
from io import StringIO
import atexit

_input = sys.stdin.read()
sys.stdin = StringIO(_input)

@atexit.register
def write():
    sys.stdout.write(_output.getvalue())

import sys
from io import StringIO
import atexit

_input = sys.stdin.read()
sys.stdin = StringIO(_input)

@atexit.register
def write():
    sys.stdout.write(_output.getvalue())

def main():
    n, m = map(int, input().split())
    h = list(map(int, input().split()))
    good = [True] * n
    for _ in range(m):
        ai, bi = map(int, input().split())
        ai -= 1
        bi -= 1
        if h[ai] > h[bi]:
            good[bi] = False
        elif h[ai] < h[bi]:
            good[ai] = False
        else:
            good[ai] = False
            good[bi] = False
    ans = sum(good)
    print(ans)

if __name__ == "__main__":
    main()


