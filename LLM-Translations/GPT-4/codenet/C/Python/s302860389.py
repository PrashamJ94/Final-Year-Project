def main():
    input_numbers = input()
    a, b, c, d = list(map(int, input_numbers))

    for i in range(2):
        for j in range(2):
            for k in range(2):
                if i == 0:
                    sum_ = a + b
                    symbols_0 = '+'
                else:
                    sum_ = a - b
                    symbols_0 = '-'
                
                if j == 0:
                    sum_ = sum_ + c
                    symbols_1 = '+'
                else:
                    sum_ = sum_ - c
                    symbols_1 = '-'
                
                if k == 0:
                    sum_ = sum_ + d
                    symbols_2 = '+'
                else:
                    sum_ = sum_ - d
                    symbols_2 = '-'
                
                if sum_ == 7:
                    print(f"{a}{symbols_0}{b}{symbols_1}{c}{symbols_2}{d}=7")
                    return

main()

