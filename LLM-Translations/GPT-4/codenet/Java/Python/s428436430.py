import sys

class CalArea:
    def area(self, w, h):
        area = w * h
        return area

if __name__ == "__main__":
    arr = [int(x) for x in sys.stdin.readline().split()]

    ab = CalArea()
    area1 = ab.area(arr[0], arr[1])
    area2 = ab.area(arr[2], arr[3])

    if area1 > area2:
        print(area1)
    elif area1 < area2:
        print(area2)
    elif area1 == area2:
        print(area1)


