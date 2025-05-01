import math

a, b = map(int, input().split())
flag = False
for i in range(1, 100001):
    if math.floor(1. * i * .08) == a and b == math.floor(.1 * i):
        print(i)
        flag = True
        break

if not flag:
    print(-1)
    

