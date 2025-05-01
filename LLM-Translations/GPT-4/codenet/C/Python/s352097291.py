def main():
    c = input()
    ans = []

    for char in c:
        if char != 'B':
            ans.append(char)
        else:
            ans = ans[:-1]

    print("".join(ans))

if __name__ == "__main__":
    main()


