import sys
from collections import deque

def main():
    n, m = map(int, input().split())
    q1 = deque(map(int, input().split()))
    q2 = deque(range(1, n + 1))
    ans = 0

    while q1:
        if q1[0] <= m:
            q1.popleft()
            ans = q2.popleft()
        else:
            x = q1.popleft()
            val = x - m
            q1.append(val)
            val2 = q2.popleft()
            q2.append(val2)

    print(ans)

if __name__ == "__main__":
    main()


