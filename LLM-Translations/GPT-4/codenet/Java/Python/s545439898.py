
def main():
    count = int(input())
    giving_numbers = list(map(int, input().split()))

    # Reversing Numbers
    for i in range(count-1, -1, -1):
        print(giving_numbers[i], end=" " if i > 0 else "\n")

if __name__ == "__main__":
    main()


