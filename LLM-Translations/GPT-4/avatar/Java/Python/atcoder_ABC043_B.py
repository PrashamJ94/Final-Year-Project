
def main():
    s = input().strip()
    d = []
    for c in s:
        if c == '0':
            d.append('0')
        elif c == '1':
            d.append('1')
        elif c == 'B':
            if len(d) > 0:
                d.pop()
    print("".join(d))

if __name__ == "__main__":
    main()


