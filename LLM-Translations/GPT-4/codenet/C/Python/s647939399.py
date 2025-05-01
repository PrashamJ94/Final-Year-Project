
def main():
    calculations = []
    i = 0
    while True:
        input_str = input().split()
        a = int(input_str[0])
        m = input_str[1]
        b = int(input_str[2])

        if m == '?':
            break

        if m == '+':
            calculations.append(a + b)
        elif m == '-':
            calculations.append(a - b)
        elif m == '*':
            calculations.append(a * b)
        elif m == '/':
            calculations.append(a // b)

        i += 1

    for result in calculations:
        print(result)

if __name__ == "__main__":
    main()


