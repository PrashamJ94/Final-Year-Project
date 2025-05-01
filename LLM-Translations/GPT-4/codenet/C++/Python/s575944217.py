
from sys import stdin

def main():
    n = int(input().strip())
    ans = [0] * n
    a_values = map(int, input().strip().split())
    for a in a_values:
        a -= 1
        ans[a] += 1
    for i in ans:
        print(i)

if __name__ == "__main__":
    main()

#
