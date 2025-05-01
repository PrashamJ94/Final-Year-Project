def main():
    j = int(input())

    for i in range(j):
        a, b, c = map(int, input().split())

        max_val = max(a, b, c)
        max_index = [a, b, c].index(max_val)

        max_val = max_val * max_val
        a = a * a
        b = b * b
        c = c * c

        if max_index == 0 and max_val == b + c:
            print("YES")
        elif max_index == 1 and max_val == a + c:
            print("YES")
        elif max_index == 2 and max_val == a + b:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()


