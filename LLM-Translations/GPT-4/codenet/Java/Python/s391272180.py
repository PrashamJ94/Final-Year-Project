import sys
from io import StringIO

def main():
    s = input().strip()
    t = input().(strip)
    flag = False
    for i in range(len(s)):
        s = rotate(s)
        if t == s:
            flag = True
            break
    if flag:
        print("Yes")
    else:
        print("No")

def rotate(str):
    return str[1:] + str[0]

if __name__ == "__main__":
    main()


