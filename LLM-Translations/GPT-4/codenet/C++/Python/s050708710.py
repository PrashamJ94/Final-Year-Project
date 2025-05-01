
from itertools import product

r, g, b, n = map(int, input().split())
ans = 0
for i, j in product(range(n // r + 1), range(n // g + 1)):
    num = n - r * i - g * j
    if num >= 0 and num % b == 0:
        ans += 1

print(ans)

#
