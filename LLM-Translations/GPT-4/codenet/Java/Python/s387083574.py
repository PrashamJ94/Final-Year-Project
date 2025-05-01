import sys
from operator import itemgetter

N = int(input())
data = {}
for i in range(1, N+1):
    data[i] = int(input())

sorted_data = sorted(data.items(), key=itemgetter(1))

for key, value in sorted_data:
    sys.stdout.write(str(key) + " ")


