def main():
    str1 = input()
    str2 = input()

    if len(str1) != len(str2):
        print("NO")
    else:
        temp = str1[::-1]
        t = 0
        i = 0
        while i < len(temp):
            if temp[i] == str2[i]:
                t += 1
            i += 1
        if len(str2) == t:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()


