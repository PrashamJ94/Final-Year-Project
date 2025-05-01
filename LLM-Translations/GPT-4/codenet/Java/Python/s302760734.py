import sys

def main():
    s = list(input().strip())
    t = list(input().strip())
    check = False
    for i in range(len(s) - len(t) + 1):
        check2 = True
        for j in range(len(t)):
            if s[i + j] != '?' and s[i + j] != t[j]:
                check2 = False
        if check2:
            check = True
            for j in range(len(t)):
                s[i + j] = t[j]
        if check:
            break
    if check:
        for i in range(len(s)):
            if s[i] == '?':
                sys.stdout.write("a")
            else:
                sys.stdout.write(s[i])
        sys.stdout.write("\n")
    else:
        print("UNRESTORABLE")

if __name__ == "__main__":
    main()


