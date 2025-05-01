import sys
from io import StringIO
import itertools

def main():
    input_data = sys.stdin.readlines()
    n = int(input_data[0].strip())
    a = list(map(int, input_data[1].strip().split()))
    a = sorted(list(set(a)))
    found = False
    for i in range(len(a)):
        if i + 1 < len(a) and i + 2 < len(a):
            if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
                found = True
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()


