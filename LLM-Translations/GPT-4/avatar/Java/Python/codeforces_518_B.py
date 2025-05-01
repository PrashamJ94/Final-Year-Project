import sys
from collections import defaultdict

def main():
    s = input().strip()
    t = input().strip()
    ura = 0
    opa = 0
    tmap = defaultdict(int)
    for ch in t:
        tmap[ch] += 1
    s = list(s)
    length = len(s)
    for i in range(length):
        ch = s[i]
        num = tmap[ch]
        if num == 0:
            continue
        if num == 1:
            del tmap[ch]
        else:
            tmap[ch] -= 1
        s[i] = 'Я'
        ura += 1
    for i in range(length):
        ch = s[i]
        rch = reverse(ch)
        num = tmap[rch]
        if num == 0:
            continue
        if num == 1:
            del tmap[rch]
        else:
            tmap[rch] -= 1
        opa += 1
    print(ura, opa)

def reverse(ch):
    if ch.islower():
        return ch.upper()
    else:
        return ch.lower()

if __name__ == "__main__":
    main()


