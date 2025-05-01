
s = input()

a, z = None, None
for i, c in enumerate(s):
    if c == 'A':
        a = i
        break

for i, c in enumerate(reversed(s)):
    if c == 'Z':
        z = len(s) - i - 1
        break

print(z - a + 1)

#
