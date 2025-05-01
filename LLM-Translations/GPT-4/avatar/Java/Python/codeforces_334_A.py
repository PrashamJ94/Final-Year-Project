
from collections import deque

def main():
    n = int(input().strip())
    square = n * n
    odd = deque()
    even = deque()
    for i in range(1, square + 1):
        if i % 2 == 0:
            even.append(i)
        else:
            odd.append(i)
    loop = square // n
    div = loop // 2
    for i in range(1, loop + 1):
        for j in range(div):
            if i % 2 == 1:
                print(str(odd.popleft()) + " " + str(even.pop()), end=" ")
            else:
                print(str(even.popleft()) + " " + str(odd.pop()), end=" ")
        print()

main()


