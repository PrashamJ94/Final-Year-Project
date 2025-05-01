
def main():
    ave = 0

    for i in range(5):
        a = float(input())
        if a <= 40:
            ave += 40
        else:
            ave += a

    ave /= 5.0

    print(round(ave))

if __name__ == '__main__':
    main()


