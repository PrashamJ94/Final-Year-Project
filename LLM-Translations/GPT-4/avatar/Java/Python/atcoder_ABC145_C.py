import math
import itertools

def main():
    N = int(input())
    pos = [list(map(int, input().split())) for _ in range(N)]

    def dist(p1, p2):
        return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

    sum_d = 0
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            sum_d += dist(pos[i], pos[j])

    print(sum_d / N)

if __name__ == "__main__":
    main()


