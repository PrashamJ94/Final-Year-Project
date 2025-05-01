Here is the translated Python code:


def main():
    while True:
        x = input()
        if x == "0":
            break
        sum = 0
        for i in range(len(x)):
            sum += int(x[i])
        print(sum)

if __name__ == "__main__":
    main()


