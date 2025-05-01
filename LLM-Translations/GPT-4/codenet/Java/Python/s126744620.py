import sys
from operator import sub

def main():
    n, k, *a = map(int, sys.stdin.buffer.read().split())
    x = [0] * 200010
    for i in a:
        x[i - 1] += 1
    x.sort(key=sub)
    ans = sum(x[:200010 - k - 1])
    print(ans)

if __name__ == '__main__':
    main()


