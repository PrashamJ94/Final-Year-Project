Sure, here is the equivalent python code for your Java code:


n = int(input())
ar = list(map(int, input().split()))
maxi = 0
mini = 0
for i in range(n):
    maxi = max(ar[i] - ar[0], ar[n-1] - ar[i])
    if i == 0:
        mini = ar[i+1] - ar[i]
    elif i == n-1:
        mini = ar[i] - ar[i-1]
    else:
        mini = min(ar[i] - ar[i-1], ar[i+1] - ar[i])
    print(mini, maxi)


