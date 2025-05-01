def main():
    A, B = map(int, input().split())
    C = A + B
    D = A - B
    E = A * B
    max_value = max(C, D, E)
    print(max_value)

if __name__ == '__main__':
    main()


