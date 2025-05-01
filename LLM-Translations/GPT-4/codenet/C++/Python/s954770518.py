
def main():
    s = [0]*11
    for i in range(10):
        s[i] = int(input())

    sorted_s = sorted(s, reverse=True)
    for i in range(3):
        print(sorted_s[i])

if __name__ == "__main__":
    main()


