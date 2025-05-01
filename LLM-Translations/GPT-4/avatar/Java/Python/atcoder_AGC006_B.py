Below is the translation of your Java code to Python:


def print_xn(x, n):
    max = n * 2 - 1
    if x == 1 or x == max:
        print('No')
        return
    print('Yes')
    ans = ''.join([str((e % max + 1)) + '\n' for e in range(x + n - 1, x + n + max - 1)])
    print(ans)

def main():
    n = int(input())
    x = int(input())
    print_xn(x, n)

if __name__ == '__main__':
    main()


