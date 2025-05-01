import sys

n = int(input().strip())
vList = list(map(int, input().strip().split()))
cList = list(map(int, input().strip().split()))
max_profit = 0

for i in range(n):
    profit = vList[i] - cList[i]
    if profit > 0:
        max_profit += profit
        
print(max_profit)


