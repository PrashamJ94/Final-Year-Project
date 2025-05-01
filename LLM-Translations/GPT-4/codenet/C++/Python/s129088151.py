
from collections import defaultdict

def main():
    n = int(input())
    T = defaultdict(bool)

    for _ in range(n):
        com, str = input().split()
        if com[0] == 'i':
            T[str] = True
        else:
            if T[str]:
                print("yes")
            else:
                print("no")

if __name__ == "__main__":
    main()


