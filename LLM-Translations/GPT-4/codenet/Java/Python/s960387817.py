def main():
    n = int(input())
    set_numbers = set()
    for _ in range(n):
        set_numbers.add(int(input()))
    print(len(set_numbers))

if __name__ == "__main__":
    main()


