
from typing import List, Tuple

def next_int(li: List[str]) -> int:
    return int(li.pop(0))

class Point:
    def __init__(self, x: int, l: int, r: int):
        self.x = x
        self.l = l
        self.r = r

def main(inputs: List[str]):
    N = next_int(inputs)
    points = []
    for _ in range(N):
        x = next_int(inputs)
        L = next_int(inputs)
        points.append(Point(x, x - L, x + L))
    points.sort(key=lambda p: p.r)

    start = points[0].r
    ans = 1
    for point in points:
        if point.l < start:
            continue
        start = point.r
        ans += 1

    print(ans)

if __name__ == "__main__":
    inputs = input().strip().split()
    main(inputs)


