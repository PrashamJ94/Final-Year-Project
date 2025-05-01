import sys
from heapq import heappush, heappop

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    A.sort()

    res = 0

    q = []
    heappush(q, (-min(A[N - 1], A[N - 1]), (A[N - 1], A[N - 1])))

    for i in range(N - 2, -1, -1):
        a = A[i]
        _, place = heappop(q)
        res += min(place[0], place[1])
        heappush(q, (-min(place[0], a), (place[0], a)))
        heappush(q, (-min(a, place[1]), (a, place[1])))

    print(res)

if __name__ == "__main__":
    main()


