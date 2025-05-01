def getChar(ch):
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

def getKey(s):
    sum = 0
    p = 1
    for c in s:
        sum += p * (getChar(c))
        p *= 5
    return sum

M = 1046527
L = 14
H = [''] * M

def h1(key):
    return key % M

def h2(key):
    return 1 + (key % (M - 1))

def find(s):
    key = getKey(s)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == s:
            return 1
        elif len(H[hash]) == 0:
            return 0
        i += 1

def insert(s):
    key = getKey(s)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == s:
            return 1
        elif len(H[hash]) == 0:
            H[hash] = s
            return 0
        i += 1

n = int(input())
for _ in range(n):
    com, s = input().split()

    if com[0] == 'i':
        insert(s)
    else:
        if find(s):
            print("yes")
        else:
            print("no")


