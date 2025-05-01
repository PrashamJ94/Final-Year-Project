import sys

def main():
    s = input().strip()
    for i in range(ord('a'), ord('z') + 1):
        char = chr(i)
        a = 0
        for j in range(len(s)):
            if char == s[j]:
                a += 1
        if a == 0:
            print(char)
            break
    else:
        print("None")

if __name__ == "__main__":
    main()


