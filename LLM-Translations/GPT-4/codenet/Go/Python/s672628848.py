
def main():
    al = [int(x) for x in input().split()]

    for n, i in enumerate(al):
        if i == 0:
            print(n + 1)
            break

if __name__ == "__main__":
    main()


