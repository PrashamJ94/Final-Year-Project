Here is the translated Python code:


from sys import stdin

def main():
    n = int(input())
    levels = list(map(int, input().split()))[1:]
    levels2 = list(map(int, input().split()))[1:]
    total_levels = set(levels + levels2)

    if len(total_levels) == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()


#End of Code
