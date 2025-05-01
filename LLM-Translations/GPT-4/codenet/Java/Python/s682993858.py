import sys

while True:
    s = input()
    if s == "0":
        break
    sum = 0
    for i in range(len(s)):
        a = s[i]
        sum += int(a)
    print(sum)

