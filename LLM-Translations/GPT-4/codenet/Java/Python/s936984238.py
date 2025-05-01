import sys

def main():
    while True:
        number = int(input())
        if number == 0:
            break

        scores = list(map(int, input().split()))
        solve(scores, number)

def solve(scores, number):
    scores.sort()
    total = sum(scores[1:number - 1])
    average = total // (number - 2)
    print(average)

if __name__ == "__main__":
    main()


