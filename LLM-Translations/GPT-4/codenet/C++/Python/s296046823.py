
import math

N, K = map(int, input().split())

v = [int(x) for x in input().split()]

# ceil((N-1) / (K-1))
count = math.ceil((N - 1) / (K - 1))
print(count)

#
