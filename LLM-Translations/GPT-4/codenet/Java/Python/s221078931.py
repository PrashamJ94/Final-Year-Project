import sys
from functools import total_ordering

@total_ordering
class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return sys.maxsize
        return self.height * self.height + self.width * self.width

    def __lt__(self, other):
        d1 = self.diagonal()
        d2 = other.diagonal()
        return d1 < d2 or (d1 == d2 and self.height < other.height)

    def __eq__(self, other):
        return self.height == other.height and self.width == other.width

def main():
    rects = [IntegralRect(i + 1, j + 1) for i in range(200) for j in range(200)]
    rects.sort()

    while True:
        h, w = map(int, input().split())

        if h == 0 and w == 0:
            break

        tmp_rect = IntegralRect(h, w)

        for rect in rects:
            if rect > tmp_rect:
                print(rect.height, rect.width)
                break

if __name__ == "__main__":
    main()


