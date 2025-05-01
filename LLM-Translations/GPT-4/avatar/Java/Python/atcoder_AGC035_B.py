Here is the translated Python code:


from collections import defaultdict

def dfs(crt, parent):
    visited[crt] = 1
    crtConnect = connect[crt]
    for child in crtConnect:
        if child == parent or visited[child] == 1:
            continue
        elif visited[child] == 2:
            print.append((crt + 1, child + 1))
            odd[crt] = not odd[crt]
        else:
            dfs(child, crt)
            if odd[child]:
                print.append((child + 1, crt + 1))
                odd[child] = not odd[child]
            else:
                print.append((crt + 1, child + 1))
                odd[crt] = not odd[crt]
    visited[crt] = 2

numNode, numEdge = map(int, input().split())
connect = defaultdict(list)
for i in range(numEdge):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    connect[a].append(b)
    connect[b].append(a)

if numEdge % 2 != 0:
    print(-1)
else:
    visited = [0]*numNode
    odd = [False]*numNode
    print = []
    dfs(0, -1)
    for i in print:
        print(" ".join(map(str, i)))


