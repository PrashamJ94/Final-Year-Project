import sys
from typing import List

def main() -> None:
    n = int(input().strip())
    list_ = list(map(int, input().strip().split()))
    odd = []
    sum_ = 0
    for i in list_:
        if i % 2 == 0:
            sum_ += i
        else:
            odd.append(i)
    odd.sort()
    for i in odd:
        sum_ += i
    if len(odd) % 2 != 0:
        sum_ -= odd[0]
    print(sum_)

if __name__ == '__main__':
    main()


