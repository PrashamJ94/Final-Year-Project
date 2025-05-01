Here is the Python version of your Java code:


from sys import stdin, stdout
from bisect import bisect_left, insort

def main():
    n = int(stdin.readline())
    left = list(range(1, n+1))
    answer = [0]*n
    for _ in range(n):
        l, r, win = map(int, stdin.readline().split())
        l -= 1
        r -= 1
        win -= 1
        temp = []
        while True:
            index = bisect_left(left, l)
            if index < len(left) and left[index] <= r+1:
                answer[left[index] - 1] = win + 1
                temp.append(left.pop(index))
                l += 1
            else:
                break
        for val in temp:
            if val != win + 1:
                left.remove(val)
        if answer[win] == 0:
            answer[win] = 0
            insort(left, win+1)
    stdout.write(' '.join(map(str, answer)) + '\n')

if __name__ == "__main__":
    main()

#End of Code
