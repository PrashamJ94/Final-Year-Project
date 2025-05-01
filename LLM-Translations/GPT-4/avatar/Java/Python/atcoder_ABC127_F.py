import heapq
from sys import stdin, stdout
t = int(stdin.readline())
heap_min, heap_max = [], []
sum_min, sum_max, sum_b = 0, 0, 0
min_value = 0
for _ in range(t):
    s = list(map(int, stdin.readline().split()))
    if s[0] == 2:
        ans = min_value
        ans *= len(heap_min)
        ans -= sum_min
        ans1 = min_value
        ans1 *= len(heap_max)
        ans1 = sum_max - ans1
        print(min_value, ans + ans1 + sum_b)
    else:
        in_value = s[1]
        sum_b += s[2]
        if in_value > min_value:
            heapq.heappush(heap_max, in_value)
            sum_max += in_value
        else:
            heapq.heappush(heap_min, -in_value)
            sum_min += in_value
        if len(heap_min) > len(heap_max):
            max_root = -heapq.heappop(heap_min)
            sum_max += max_root
            sum_min -= max_root
            heapq.heappush(heap_max, max_root)
        if len(heap_min) < len(heap_max):
            min_root = heapq.heappop(heap_max)
            sum_max -= min_root
            sum_min += min_root
            heapq.heappush(heap_min, -min_root)
        min_value = heap_max[0]


