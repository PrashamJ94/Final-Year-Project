import sys
from sys import stdin

def rec(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k)) != 0:
            answer += 1
    return answer

def main():
    n = int(input().strip())
    a = [0] * 33
    for _ in range(n):
        a[rec(int(input().strip()))] += 1
    answer = 0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ
    print(int(answer))

if __name__ == "__main__":
    main()


