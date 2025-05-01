
from collections import deque

class Process:
    def __init__(self, name, time):
        self.name = name
        self.time = time

def min(a, b):
    return a if a < b else b

def main():
    elaps = 0
    n, q = map(int, input().split())
    queue = deque()

    for _ in range(n):
        name, time = input().split()
        time = int(time)
        process = Process(name, time)
        queue.append(process)

    while queue:
        u = queue.popleft()
        c = min(q, u.time)
        u.time -= c
        elaps += c
        if u.time > 0:
            queue.append(u)
        else:
            print(f"{u.name} {elaps}")

if __name__ == "__main__":
    main()


