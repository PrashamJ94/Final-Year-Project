import sys

def main():
    input_data = sys.stdin.readlines()
    int_loop = int(input_data[0].strip())
    str_taro = ""
    str_hana = ""
    int_taro = 0
    int_hana = 0

    for i in range(1, int_loop * 2, 2):
        str_taro = input_data[i].strip()
        str_hana = input_data[i + 1].strip()
        int_judge = (str_taro > str_hana) - (str_taro < str_hana)
        if int_judge < 0:
            int_hana += 3
        elif int_judge == 0:
            int_taro += 1
            int_hana += 1
        elif 0 < int_judge:
            int_taro += 3

    print(int_taro, int_hana)

if __name__ == '__main__':
    main()


