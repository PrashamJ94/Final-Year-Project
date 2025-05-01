
def push(stack, chonda):
    stack.append(chonda)

def pop(stack):
    return stack.pop()

def main():
    stack = []
    while True:
        try:
            null = input()
        except EOFError:
            break

        if null == '+':
            chonda = pop(stack)
            yamagami = pop(stack)
            push(stack, chonda + yamagami)
        elif null == '-':
            yamagami = pop(stack)
            chonda = pop(stack)
            push(stack, chonda - yamagami)
        elif null == '*':
            chonda = pop(stack)
            yamagami = pop(stack)
            push(stack, chonda * yamagami)
        else:
            push(stack, int(null))

    print(pop(stack))

if __name__ == "__main__":
    main()


