Here is the Python code equivalent of the Java code you provided:


n, k = map(int, input().split())
arr = list(map(int, input().split()))
res = []
o = e = 0
for i in range(n):
    if arr[i] == 1:
        o += 1
    else:
        e += 1
for _ in range(k):
    l, r = map(int, input().split())
    if (r - l + 1) % 2 == 1:
        res.append('0')
    else:
        if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
            res.append('1')
        else:
            res.append('0')
print('\n'.join(res))


