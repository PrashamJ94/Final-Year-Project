def comp(x, a):
    if x < a:
        return 0
    return 10

def main():
    x, a = map(int, input().split())
    print(comp(x, a))

if __name__ == "__main__":
    main()


