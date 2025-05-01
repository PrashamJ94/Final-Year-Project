import sys
from typing import List, Tuple

def main():
    a = list(map(int, sys.stdin.readline().split()))
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

if __name__ == "__main__":
    main()


