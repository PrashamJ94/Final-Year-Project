
import sys

def main():
    t = int(input().strip())
    count = 0
    for _ in range(t):
        a, b, c = map(int, input().strip().split())
        if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
            count += 1
    print(count)

if __name__ == "__main__":
    main()


