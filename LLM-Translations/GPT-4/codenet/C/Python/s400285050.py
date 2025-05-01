def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

x, y = map(int, input().split())
if x >= y:
    z = gcd(x, y)
else:
    z = gcd(y, x)

print(z)

