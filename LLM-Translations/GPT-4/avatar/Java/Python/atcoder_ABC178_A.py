
import sys

def main():
    x = int(input().strip())
    bool_value = True if x == 1 else False
    result = 1 if not bool_value else 0
    print(result)

if __name__ == "__main__":
    main()


