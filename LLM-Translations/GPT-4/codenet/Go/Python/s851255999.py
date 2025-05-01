
from typing import List, Tuple
import sys

def main():
    n = int(input().strip())
    ws = []
    for _ in range(n):
        a, n = map(int, input().split())
        ws.append((a, n))
    ws.sort(key=lambda x: x[1])

    total_time = 0
    for w in ws:
        total_time += w[0]
        if total_time > w[1]:
            print("No")
            return
    print("Yes")

if __name__ == "__main__":
    main()


