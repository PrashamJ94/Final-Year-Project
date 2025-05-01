import sys

def main():
    s, k = input().strip().split()
    k = int(k)
    sb = []
    for i in range(len(s)):
        if (26 - (ord(s[i]) - ord('a'))) <= k and s[i] != 'a':
            k -= 26 - (ord(s[i]) - ord('a'))
            sb.append('a')
        else:
            sb.append(s[i])
    if k > 0:
        t = sb[-1]
        sb[-1] = chr(ord('a') + (ord(t) - ord('a') + k) % 26)
    print(''.join(sb))

if __name__ == "__main__":
    main()


