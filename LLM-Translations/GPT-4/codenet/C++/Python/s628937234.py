def main():
    s = input()
    t = s[0]
    t += str(len(s) - 2)
    t += s[-1]
    print(t)

if __name__ == "__main__":
    main()


