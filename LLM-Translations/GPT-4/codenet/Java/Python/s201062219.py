
def main():
    inputs = []
    results = []
    while True:
        c = int(input())
        mark = input()
        b = int(input())

        if mark == "?":
            break
        elif mark == "+":
            results.append(c + b)
        elif mark == "-":
            results.append(c - b)
        elif mark == "*":
            results.append(c * b)
        elif mark == "/":
            results.append(c // b)

    for result in results:
        print(result)

if __name__ == "__main__":
    main()


