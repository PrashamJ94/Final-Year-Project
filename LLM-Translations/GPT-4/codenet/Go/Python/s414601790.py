def main():
    n, s = input().split()
    n = int(n)

    max_value = 0
    cnt = 0
    for r in s:
        if r == 'I':
            cnt += 1
        else:
            cnt -= 1

        if cnt > max_value:
            max_value = cnt

    print(max_value)

if __name__ == "__main__":
    main()


