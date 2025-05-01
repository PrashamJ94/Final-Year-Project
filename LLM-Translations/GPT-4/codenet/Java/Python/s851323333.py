import sys

class Main:
    def __init__(self):
        self.list = []

    def main(self):
        for line in sys.stdin:
            a = int(line.strip())
            if a == 0:
                print(self.list.pop())
            else:
                self.list.append(a)

if __name__ == "__main__":
    main = Main()
    main.main()


