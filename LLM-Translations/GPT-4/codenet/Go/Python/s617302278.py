
from itertools import accumulate

x = int(input())

i = 1
sum_ = 0
for sum_ in accumulate(range(1, x + 1)):
    if sum_ >= x:
        break
    i += 1

print(i)

#
