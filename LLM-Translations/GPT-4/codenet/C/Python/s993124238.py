
import math

def main():
    n, d = map(int, input().split())
    points = [list(map(int, input().split())) for _ in range(n)]

    count = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            sum = 0
            for k in range(d):
                sum += (points[i][k] - points[j][k]) ** 2
            kyori = math.sqrt(sum)
            if math.ceil(kyori) == math.floor(kyori):
                count += 1

    print(count)

if __name__ == "__main__":
    main()


