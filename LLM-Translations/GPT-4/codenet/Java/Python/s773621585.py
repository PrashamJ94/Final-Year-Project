import sys

def main():
    map = {}
    n = int(input())
    for _ in range(n):
        map[input()] = ""
    print(len(map))

if __name__ == "__main__":
    main()


