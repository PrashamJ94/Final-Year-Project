
def main():
    a, b = map(int, input().split())
    print(max(a + b, max(a - b, a * b)))

if __name__ == "__main__":
    main()


#
