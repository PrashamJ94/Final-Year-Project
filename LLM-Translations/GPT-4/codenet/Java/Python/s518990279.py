import sys

def main():
    while True:
        inputed = input().strip()
        if inputed == '0':
            break

        ans = 0
        for char in inputed:
            ans += int(char)

        print(ans)

if __name__ == '__main__':
    main()


