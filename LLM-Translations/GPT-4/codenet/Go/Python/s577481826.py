def main():
    a = int(input())
    b = int(input())

    ret = a + b

    if ret < (a - b):
        ret = a - b
    if ret < (a * b):
        ret = a * b

    print(ret)

if __name__ == "__main__":
    main()


