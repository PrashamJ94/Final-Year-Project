
from sys import stdin

N = 100000
INF = 1000000

class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

def root(a, b):
    d = [INF] * n
    d[0] = 0
    flag = 1

    while flag != 0:
        flag = 0
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1
                
    return d

def main():
    n = int(input().strip())
    a = []
    count = 0
    for _ in range(n):
        u, k, *edges = map(int, input().strip().split())
        for j in range(0, len(edges), 2):
            go, cost = edges[j], edges[j+1]
            a.append(Date(go, u, cost))
            count += 1
            
    d = root(a, count)
    for i in range(n):
        print(i, d[i])

if __name__ == "__main__":
    main()


#
