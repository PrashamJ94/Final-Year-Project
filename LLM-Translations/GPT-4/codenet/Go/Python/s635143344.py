def main():
    in_list = [int(x) for x in input().split()]
    in_list.sort()

    print(in_list[2]*10 + in_list[1] + in_list[0])

if __name__ == "__main__":
    main()


