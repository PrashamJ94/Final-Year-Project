
import sys

def main():
    N = int(input())
    data = list(map(int, sys.stdin.readline().split()))
    v = [0] * N

    for a in data:
        v[a-1] += 1

    for e in v:
        print(e)

if __name__ == "__main__":
    main()



