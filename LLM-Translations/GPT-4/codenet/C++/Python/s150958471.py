
from sys import stdin

def main():
    train = list(map(int, input().split()))
    bus = list(map(int, input().split()))

    print(min(train) + min(bus))

if __name__ == "__main__":
    main()


#
