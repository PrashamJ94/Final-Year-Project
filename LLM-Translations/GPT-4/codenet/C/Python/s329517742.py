def main():
    a, b = map(int, input().split())
    if 500 * a >= b:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


