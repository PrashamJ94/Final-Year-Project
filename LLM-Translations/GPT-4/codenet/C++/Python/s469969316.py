import sys

def Not(x):
    return 2-x

def And(x, y):
    if x*y == 0:
        return 0
    if x == 2 and y == 2:
        return 2
    return 1

def Or(x, y):
    if x == 2 or y == 2:
        return 2
    if x == 1 or y == 1:
        return 1
    return 0

def parse(ss, it):
    c = ss[it]
    it += 1
    if '0' <= c <= '2':
        return int(c), it
    if c == '-':
        res, it = parse(ss, it)
        return Not(res), it

    x, it = parse(ss, it)
    c = ss[it]
    it += 1
    y, it = parse(ss, it)
    it += 1
    return (And(x, y) if c == '*' else Or(x, y)), it

while True:
    input_str = input().strip()
    if input_str == ".":
        break

    a = [0, 0, 0]
    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a[0] = i
                a[1] = j
                a[2] = k
                ss = input_str
                ss = ss.replace('P', str(a[0]))
                ss = ss.replace('Q', str(a[1]))
                ss = ss.replace('R', str(a[2]))
                it = 0
                res, _ = parse(ss, it)
                if res == 2:
                    cnt += 1
    print(cnt)


