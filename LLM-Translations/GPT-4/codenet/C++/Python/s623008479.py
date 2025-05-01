
from sys import stdin
n, k = map(int, input().split())
l = [int(x) for x in input().split()]

l.sort(reverse=True)

ans = 0
for i in range(k):
    ans += l[i]

print(ans)


