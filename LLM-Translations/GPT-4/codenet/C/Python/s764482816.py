
def main():
    io = list(map(int, input().split()))

    for i in range(5):
        max_val = io[i]
        max_j = i
        for j in range(i + 1, 5):
            if max_val < io[j]:
                max_val = io[j]
                max_j = j
        buf = io[i]
        io[i] = io[max_j]
        io[max_j] = buf
        if i < 4:
            print(io[i], end=" ")
        else:
            print(io[i])

if __name__ == "__main__":
    main()


