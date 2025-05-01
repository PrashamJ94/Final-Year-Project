import re

def main():
    num = int(input())
    num_list = [i + 1 for i in range(num)]
    count = int(input())
    pattern = re.compile(r"(\d+),(\d+)")
    
    for _ in range(count):
        next_input = input()
        line = [int(match.group(i + 1)) - 1 for i, match in enumerate(re.finditer(pattern, next_input))]
        change = num_list[line[0]]
        num_list[line[0]] = num_list[line[1]]
        num_list[line[1]] = change
    
    for num in num_list:
        print(num)

if __name__ == "__main__":
    main()


