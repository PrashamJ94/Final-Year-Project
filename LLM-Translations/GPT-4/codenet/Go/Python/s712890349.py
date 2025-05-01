
from collections import namedtuple

Block = namedtuple("Block", ["Value", "Len"])

def main():
    N, K = map(int, input().split())
    S = input()
    blocks = run_length(S)
    ans, zero, l, sum_ = 0, 0, 0, 0
    for r in range(len(blocks)):
        sum_ += blocks[r].Len
        if blocks[r].Value == "0":
            zero += 1
        while K < zero:
            sum_ -= blocks[l].Len
            if blocks[l].Value == "0":
                zero -= 1
            l += 1
        ans = max(ans, sum_)
    print(ans)

def run_length(s):
    if len(s) == 0:
        return []
    r = []
    t = Block(Value=s[0], Len=1)
    for v in s[1:]:
        if t.Value == v:
            t = Block(Value=t.Value, Len=t.Len+1)
        else:
            r.append(t)
            t = Block(Value=v, Len=1)
    r.append(t)
    return r

def max(a, b):
    return b if b > a else a

if __name__ == "__main__":
    main()


