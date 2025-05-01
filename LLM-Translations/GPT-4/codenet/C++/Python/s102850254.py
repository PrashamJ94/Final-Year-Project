import sys
from typing import List

def visit(n: int, map: List[str]) -> None:
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    flg = 0
    x = 2
    y = n
    map[y] = map[y][:x] + ' ' + map[y][x+1:]
    ab = [2, 2, 2, 2]

    while True:
        sum = 0
        while True:
            if (map[y+dy[flg]*2][x+dx[flg]*2] != '#' and
                map[y+dy[flg]][x+dx[flg]] != ' '):
                flg += 1
                break

            map[y+dy[flg]] = (map[y+dy[flg]][:x+dx[flg]] + ' ' +
                             map[y+dy[flg]][x+dx[flg]+1:])
            y += dy[flg]
            x += dx[flg]
            sum += 1

        if flg == 4:
            flg = 0

        if sum == 0:
            break
        ab[0], ab[1], ab[2] = ab[1], ab[2], sum

        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
            break

def main():
    d = int(input().strip())

    for l in range(d):
        n = int(input().strip())
        if n == 1:
            print("#")
            if l != d-1:
                print()
            continue

        map = ['#' * (n+2)]
        for _ in range(n):
            map.append('#' + '.' * n + '#')
        map.append(map[0])

        visit(n, map)

        for i in range(1, n+1):
            print(map[i][1:-1])

        if l != d-1:
            print()

if __name__ == "__main__":
    main()


