import sys

def main():
    a = sys.stdin.readline().strip()
    result = a.replace(",", " ")
    print(result)

if __name__ == "__main__":
    main()


