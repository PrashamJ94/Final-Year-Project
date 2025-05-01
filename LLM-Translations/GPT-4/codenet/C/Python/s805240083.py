
from collections import deque

MAX = 100005
N = 100

class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

def main():
    n, q = map(int, input().split())
    Q = deque()

    for _ in range(n):
        name, t = input().split()
        t = int(t)
        Q.append(P(name, t))

    T = 0
    while n != 0:
        a = Q.popleft()
        if a.t > q:
            a.t = a.t - q
            T += q
            Q.append(a)
        else:
            T = T + a.t
            print(a.name, T)
            n -= 1

if __name__ == "__main__":
    main()


