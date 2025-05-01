def main():
    s = input()

    for j in range(len(s)):
        for i in range(len(s)):
            if i != j and s[i] == s[j]:
                print("no")
                return

    print("yes")

if __name__ == "__main__":
    main()


