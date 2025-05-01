
a, b, c = map(int, input().split())

d = c - a - b

if d > 0 and (4 * a * b) < d**2:
    print("Yes")
else:
    print("No")

#
