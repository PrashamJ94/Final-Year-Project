import sys
from collections import deque

def main():
    n, q = map(int, input().split())
    Q = deque()

    for _ in range(n):
        name, time = input().split()
        time = int(time)
        Q.append((name, time))

    elaps = 0

    while Q:
        name, time = Q.popleft()
        if time <= q:
            elaps += time
            print(name, elaps)
        else:
            time -= q
            elaps += q
            Q.append((name, time))

if __name__ == "__main__":
    main()


