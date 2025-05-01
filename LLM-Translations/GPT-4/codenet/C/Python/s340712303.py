
N = 2000

def main():
    num1 = int(input())
    math = [0] * (N + 1)
    math[0] = 1
    sum_ = 0

    for _ in range(num1):
        a = int(input())
        sum_ += a
        for j in range(sum_ - a, -1, -1):
            if math[j] == 1:
                math[j + a] = 1

    num2 = int(input())
    for _ in range(num2):
        ans = int(input())
        print("yes" if math[ans] == 1 else "no")

if __name__ == "__main__":
    main()


