def main():
    input_array = input().split()
    result = 0
    for str in input_array:
        result += 1
        if "0" == str:
            break
    print(result)

if __name__ == "__main__":
    main()


