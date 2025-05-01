def push(stack, x):
    stack.append(x)

def pop(stack):
    return stack.pop()

def main():
    stack = []
    while True:
        try:
            s = input().split()
        except EOFError:
            break

        for token in s:
            if token == '+':
                b = pop(stack)
                a = pop(stack)
                push(stack, a + b)
            elif token == '-':
                b = pop(stack)
                a = pop(stack)
                push(stack, a - b)
            elif token == '*':
                b = pop(stack)
                a = pop(stack)
                push(stack, a * b)
            else:
                push(stack, int(token))

    print(pop(stack))

if __name__ == "__main__":
    main()


