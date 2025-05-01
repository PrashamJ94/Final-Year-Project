import sys

def main():
    size = int(input())
    graph = [[0] * size for _ in range(size)]

    for _ in range(size):
        id_and_cols = list(map(int, input().split()))
        id = id_and_cols[0]
        cols = id_and_cols[1]
        row = [0] * size
        for j in range(2, len(id_and_cols)):
            row[id_and_cols[j] - 1] = 1
        graph[id - 1] = row

    for i in range(len(graph)):
        for j in range(len(graph[i])):
            print(graph[i][j], end=" ")
        print()

if __name__ == "__main__":
    main()


