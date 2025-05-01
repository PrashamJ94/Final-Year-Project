def bin_print(x, bits):
    for i in range(bits - 1, -1, -1):
        print((x & (1 << i)) and 1 or 0, end="")
    print()


if __name__ == "__main__":
    a, b = map(int, input().split())

    bin_print(a & b, 32)
    bin_print(a | b, 32)
    bin_print(a ^ b, 32)


