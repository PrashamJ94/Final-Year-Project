
from sys import stdin

def main():
    str = input().strip()
    sum = 0
    for x in str:
        sum += int(x)
    if sum % 9 == 0:
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()


