Here is your Java code translated to Python:


n = int(input())
FfriendPerDay = [0]*367
MfriendPerDay = [0]*367
answer = 0
for i in range(n):
    c, a, b = input().split()
    a = int(a)
    b = int(b)
    for j in range(a, b+1):
        if c == 'M':
            MfriendPerDay[j] += 1
        else:
            FfriendPerDay[j] += 1
        if MfriendPerDay[j] < FfriendPerDay[j]:
            answer = max(answer, MfriendPerDay[j])
        else:
            answer = max(answer, FfriendPerDay[j])
print(answer * 2)


