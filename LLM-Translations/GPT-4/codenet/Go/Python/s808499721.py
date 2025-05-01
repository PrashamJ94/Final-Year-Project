
x = int(input())

ans = 0
if 400 <= x <= 599:
    ans = 8
elif 600 <= x <= 799:
    ans = 7
elif 800 <= x <= 999:
    ans = 6
elif 1000 <= x <= 1199:
    ans = 5
elif 1200 <= x <= 1399:
    ans = 4
elif 1400 <= x <= 1599:
    ans = 3
elif 1600 <= x <= 1799:
    ans = 2
elif 1800 <= x <= 9999:
    ans = 1

print(ans)


