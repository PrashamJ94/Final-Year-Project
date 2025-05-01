
def main():
    N = int(input())
    numbers = [int(input()) for _ in range(N)]

    count = 0

    while all(i % 2 == 0 for i in numbers):
        numbers = [i // 2 for i in numbers]
        count += 1

    print(count)

if __name__ == "__main__":
    main()


