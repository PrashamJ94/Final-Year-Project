import sys

def main():
    c = input()
    letter = c[0]
    letter = chr(ord(letter) + 1)

    print(letter)

if __name__ == "__main__":
    main()


