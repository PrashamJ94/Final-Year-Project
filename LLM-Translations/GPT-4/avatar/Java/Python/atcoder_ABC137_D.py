import heapq
from operator import itemgetter

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

N, M = map(int, input().split())
jobs = []
for _ in range(N):
    a, b = map(int, input().split())
    jobs.append(Job(a, b))

jobs.sort(key=itemgetter(0), reverse=True)

q = []
cnt = 0
for i in range(1, M+1):
    while jobs and jobs[-1].a <= i:
        heapq.heappush(q, -jobs.pop().b)
    if q:
        cnt += -heapq.heappop(q)

print(cnt)

