import sys
from io import StringIO

def get_fail(b, m):
    j = 0
    f = [0] * (m + 1)
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j
    return f

def main():
    input = sys.stdin.readline().strip()
    n = int(input)
    s1, str = input().split()
    cnt = 0
    b = [0] * (2 * n + 1)
    for i in range(n):
        cnt += 1
        b[cnt] = str[i]
    for i in range(n):
        cnt += 1
        b[cnt] = s1[i]
    f = get_fail(b, cnt)
    len_ = min(f[cnt], min(n, n))
    print(2 * n - len_)

if __name__ == "__main__":
    main()


