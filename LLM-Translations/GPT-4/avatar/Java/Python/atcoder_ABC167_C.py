import sys
from itertools import product

def main():
    n, m, x = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    min_cost = sys.maxsize

    for status in product((0, 1), repeat=n):
        res = [0] * (m + 1)
        for j in range(n):
            if status[j] == 1:
                for k in range(m + 1):
                    res[k] += a[j][k]

        flag = all(res[j] >= x for j in range(1, m + 1))

        if flag:
            min_cost = min(min_cost, res[0])

    if min_cost == sys.maxsize:
        print(-1)
    else:
        print(min_cost)

if __name__ == "__main__":
    main()


