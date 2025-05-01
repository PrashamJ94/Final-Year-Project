
while True:
    user_input = input().split()
    a, S, b = int(user_input[0]), user_input[1], int(user_input[2])

    if S == '+':
        print(a + b)
    elif S == '-':
        print(a - b)
    elif S == '*':
        print(a * b)
    elif S == '/':
        print(a / b)
    elif S == '?':
        break


