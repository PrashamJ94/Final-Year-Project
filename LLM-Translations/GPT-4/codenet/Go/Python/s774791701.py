def main():
    s = input()

    price = 700
    for c in s:
        if c == 'o':
            price += 100
    print(price)

if __name__ == "__main__":
    main()


