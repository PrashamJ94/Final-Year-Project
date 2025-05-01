
from functools import cmp_to_key

class Edge:
    def __init__(self, p, i, s):
        self.p = p
        self.i = i
        self.s = s

def esort(e1, e2):
    if e1.s != e2.s:
        return (e1.s > e2.s) - (e1.s < e2.s)
    if e1.p < e2.p:
        return 1
    return -1

n = int(input())
data = []

for i in range(n):
    s, p = input().split()
    p = int(p)
    data.append(Edge(p, i, s))

data.sort(key=cmp_to_key(esort))

for i in range(n):
    print(data[i].i + 1)

#
