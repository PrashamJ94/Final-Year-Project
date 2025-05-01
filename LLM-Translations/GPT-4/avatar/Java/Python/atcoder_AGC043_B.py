
from sys import stdin
from itertools import accumulate

def cal(s, c):
    n = len(s)
    m = n - 1
    ans = 0
    for i in range(n):
        if s[i] == c and (m & i) == i:
            ans ^= 1
    return ans

def main():
    n = int(input().strip())
    s = input().strip()
    sb = []
    for i in range(1, n):
        sb.append(abs(ord(s[i]) - ord(s[i - 1])))
    if n == 2:
        print(sb[0])
        return
    s = ''.join(map(str, sb))
    if '1' in s:
        print(cal(s, '1'))
    else:
        print(cal(s, '2') * 2)

if __name__ == "__main__":
    main()

#End of Code
