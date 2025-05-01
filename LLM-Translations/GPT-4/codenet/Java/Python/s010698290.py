
from sys import stdin

def main():
    n, m = map(int, input().split())

    penal = [0] * (n + 1)
    solved = [False] * (n + 1)

    for _ in range(m):
        num, str = input().split()
        num = int(num)
        if str == 'A':
            solved[num] = True
        elif not solved[num]:
            penal[num] += 1

    correct_ans = 0
    num_penal = 0
    for i in range(1, n + 1):
        if solved[i]:
            correct_ans += 1
            num_penal += penal[i]

    print(correct_ans, num_penal)

if __name__ == "__main__":
    main()


