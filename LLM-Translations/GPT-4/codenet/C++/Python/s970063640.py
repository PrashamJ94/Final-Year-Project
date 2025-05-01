
from sys import stdin
def main():
    n = int(input())
    a = int(input())
    sum = 0
    s = list(map(int, input().split()))
    s.sort(reverse=True)
    for i in range(a):
        sum += s[i]
    print(sum)

if __name__ == '__main__':
    main()

#
