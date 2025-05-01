Here's the Python code equivalent of your Java code:


n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
num = [0]*(n+1)
for i in range(1, n+1):
    num[b[i]] += 1
ss = ""
ans = 0
st = [False]*(n+1)
for i in range(1, n+1):
    if a[i] == 1:
        st[i] = True
        sb = []
        x = b[i]
        sss = [i]
        sb.append(" " + str(sss[::-1][0]))
        s = 1
        while not st[x] and num[x] == 1 and x != 0 and a[x] != 1:
            sss = [x]
            sb.append(" " + str(sss[::-1][0]))
            st[x] = True
            x = b[x]
            s += 1
        if s > ans:
            ans = s
            ss = " ".join(sb[::-1])
print(ans)
print(ss)


