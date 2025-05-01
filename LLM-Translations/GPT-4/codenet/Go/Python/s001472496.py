def main():
    s = input()

    max_tmp = 0
    max_val = 0
    for i in range(len(s)):
        flag = False
        if s[i] in ["A", "C", "T", "G"]:
            max_tmp += 1
        else:
            flag = True

        if i == len(s) - 1:
            flag = True
        if flag:
            if max_val < max_tmp:
                max_val = max_tmp
            max_tmp = 0
    print(max_val)

if __name__ == "__main__":
    main()


