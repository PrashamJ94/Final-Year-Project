
from collections import defaultdict

def main():
    while True:
        n = int(input())
        if not n:
            break
        v = []
        d = defaultdict(list)
        for i in range(n):
            name, m = input().split()
            m = int(m)
            score = 0
            for _ in range(m):
                a = int(input())
                score += n - len(d[a])
                for k in d[a]:
                    v[k][0] -= 1
                d[a].append(i)
            v.append([score, name])
        v.sort()
        print(v[0][0], v[0][1])

if __name__ == "__main__":
    main()


