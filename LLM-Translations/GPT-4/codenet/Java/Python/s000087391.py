import sys

def main():
    result = []
    while True:
        n = int(input().strip())
        if n == 0:
            break
        _ = input().strip()
        array2 = input().strip().split()
        input_values = [int(x) for x in array2]
        total = sum(input_values)
        avg = total / n
        num = sum(1 for x in input_values if x <= avg)
        result.append(num)

    for res in result:
        if res == -1:
            print("NONE")
        else:
            print(res)

if __name__ == "__main__":
    main()


