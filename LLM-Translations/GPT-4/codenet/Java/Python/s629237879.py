import sys

def main():
    n = int(input().strip())
    str_list = []
    for _ in range(n):
        str_list.append(input().strip())
    mark = ["S", "H", "C", "D"]
    for ma in mark:
        for i in range(1, 14):
            s = str(i)
            st = ma + " " + s
            if st in str_list:
                continue
            else:
                print(st)

if __name__ == "__main__":
    main()


