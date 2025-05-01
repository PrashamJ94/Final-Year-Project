def main():
    alpha = [0] * 26

    while True:
        try:
            ch = input()
        except EOFError:
            break

        if ch.isalpha():
            if ch.isupper():
                alpha[ord(ch) - 65] += 1
            else:
                alpha[ord(ch) - 97] += 1

    ch = 'a'
    for i in range(26):
        print(f"{ch} : {alpha[i]}")
        ch = chr(ord(ch) + 1)


if __name__ == "__main__":
    main()


