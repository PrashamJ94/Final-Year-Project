
t_values = []
n_values = []
for _ in range(4):
    t, n = map(int, input().split())
    t_values.append(t)
    n_values.append(n)

for i in range(4):
    t = t_values[i]
    n = n_values[i]
    if t == 1:
        print(6000 * n)
    elif t == 2:
        print(4000 * n)
    elif t == 3:
        print(3000 * n)
    elif t == 4:
        print(2000 * n)

#
