Here is your Java program translated to Python:


import sys

n, m = map(int, input().strip().split())
ans = []

for i in range(n):
    str = input().strip()
    temp = ""

    for j in range(m):
        if str[j] == '-':
            temp += '-'
        else:
            if (i + j) % 2 == 1:
                temp += 'W'
            else:
                temp += 'B'
    ans.append(temp)

for i in range(n):
    print(ans[i])

##End of Code.
