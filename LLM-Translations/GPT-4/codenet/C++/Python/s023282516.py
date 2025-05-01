
def main():
    S = input().strip()

    divide = ["dream", "dreamer", "erase", "eraser"]

    # Reverse the strings for easier processing
    S = S[::-1]
    for i in range(4):
        divide[i] = divide[i][::-1]

    idx = 0
    can = True
    while idx < len(S):
        can2 = False
        for j in range(4):
            d = divide[j]
            if S[idx:idx + len(d)] == d:
                can2 = True
                idx += len(d)
                break
        if not can2:
            can = False
            break

    if can:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()


