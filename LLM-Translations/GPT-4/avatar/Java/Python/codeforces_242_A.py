
from itertools import product

x, y, a, b = map(int, input().split())
count = 0
results = []

for i, j in product(range(a, x + 1), range(b, y + 1)):
    if i > j:
        count += 1
        results.append((i, j))

print(count)
for result in results:
    print(result[0], result[1])


