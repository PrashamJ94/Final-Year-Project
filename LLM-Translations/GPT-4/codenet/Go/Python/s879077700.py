def main():
    a = input()
    ans = "Good"
    for i in range(3):
        if a[i] == a[i+1]:
            ans = "Bad"
    print(ans)

if __name__ == "__main__":
    main()


