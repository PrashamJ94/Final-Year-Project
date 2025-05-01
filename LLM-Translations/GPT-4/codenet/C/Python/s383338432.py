def main():
    height, width = map(int, input().split())
    print("#" * (width + 2))
    for i in range(height):
        input_str = input()
        print(f"#{input_str}#")
    print("#" * (width + 2))

if __name__ == "__main__":
    main()


