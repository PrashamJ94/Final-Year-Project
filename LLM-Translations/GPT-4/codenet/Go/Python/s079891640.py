def main():
    s = input()

    for i in range(len(s)):
        if s[i] in s[i+1:]:
            print("no")
            return

    print("yes")


if __name__ == "__main__":
    main()


