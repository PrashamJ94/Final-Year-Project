
def init(i):
    global x, y, fld
    x = y = 10
    fld = [[0 for _ in range(MAX)] for _ in range(MAX)]
    for _ in range(i):
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(i):
    global x, y, fld, n
    for _ in range(i):
        buf, a = input().split()
        a = int(a)
        if buf == 'N':
            d = 0
        elif buf == 'E':
            d = 1
        elif buf == 'S':
            d = 2
        elif buf == 'W':
            d = 3

        for _ in range(a):
            if d % 2:
                if d == 1:
                    x -= 1
                else:
                    x += 1
            else:
                if d == 2:
                    y -= 1
                else:
                    y += 1

            if fld[y][x]:
                fld[y][x] = 0
                n -= 1

def main():
    global n
    while True:
        n = int(input())
        if n == 0:
            break
        init(n)
        m = int(input())
        move(m)
        print("No" if n else "Yes")

if __name__ == "__main__":
    MAX = 21
    main()

#
