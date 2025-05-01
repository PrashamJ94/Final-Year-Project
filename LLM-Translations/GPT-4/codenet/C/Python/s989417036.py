
def main():
    a, b, c = map(int, input().split())
    if b <= c:
        print("NO")
        return
    else:
        d = a
        e = d % b
        for i in range(b):
            d = d % b
            if d == c:
                print("YES")
                return
            elif i != 0 and d == c:
                print("NO")
                return
            d += a
    print("NO")

if __name__ == "__main__":
    main()

#
