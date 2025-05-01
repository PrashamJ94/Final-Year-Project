def main():
    N = 1000
    while True:
        su = input()
        if su == '0':
            break
        susum = sum(int(c) for c in su)
        print(susum)


if __name__ == "__main__":
    main()


