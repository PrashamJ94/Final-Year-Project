
from typing import List

def main():
    N, L = map(int, input().split())
    v = []

    for _ in range(N):
        s = input()
        v.append(s)

    v.sort()

    for word in v:
        print(word, end="")
    print()

if __name__ == "__main__":
    main()


