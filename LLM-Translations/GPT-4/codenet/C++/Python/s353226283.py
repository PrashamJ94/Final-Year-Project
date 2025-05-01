
from sys import stdin
n, k = map(int, input().split())
vec = [int(x) for x in input().split()]
vec.sort()
ans = 1000000001
for i in range(n - k + 1):
    diff = vec[i + k - 1] - vec[i]
    if diff < ans:
        ans = diff
print(ans)

#
