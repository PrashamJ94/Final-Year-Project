
def mul(str, idx):
    res = int(str[idx])
    while idx + 1 < len(str) and str[idx + 1] == '*':
        idx += 2
        res *= int(str[idx])
    return res, idx

def add(str, idx):
    res, idx = mul(str, idx)
    while idx + 1 < len(str) and str[idx + 1] == '+':
        idx += 2
        temp, idx = mul(str, idx)
        res += temp
    return res, idx

def bob(str, idx):
    res = int(str[idx])
    while idx + 1 < len(str):
        if str[idx + 1] == '+':
            res += int(str[idx + 2])
        else:
            res *= int(str[idx + 2])
        idx += 2
    return res

while True:
    try:
        s, d = input().split()
        d = int(d)
        
        idx = 0
        a, idx = add(s, idx)
        idx = 0
        b = bob(s, idx)
        
        if a == d:
            print("U" if b == d else "M")
        else:
            print("L" if b == d else "I")
    except EOFError:
        break

#
