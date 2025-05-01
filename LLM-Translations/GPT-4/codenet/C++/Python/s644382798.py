
from collections import deque

class Process:
    def __init__(self, name, time):
        self.name = name
        self.time = time

def min(a, b):
    return a if a < b else b

def main():
    n, q = map(int, input().split())
    queue = deque()
    for _ in range(n):
        name, time = input().split()
        time = int(time)
        queue.append(Process(name, time))

    elaps = 0
    while queue:
        process = queue.popleft()
        c = min(q, process.time)
        process.time -= c
        elaps += c
        if process.time > 0:
            queue.append(process)
        else:
            print(f"{process.name} {elaps}")

if __name__ == "__main__":
    main()



