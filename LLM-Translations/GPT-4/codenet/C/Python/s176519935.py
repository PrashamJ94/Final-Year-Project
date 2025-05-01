
import heapq

def push(heap, x):
    heapq.heappush(heap, -x)

def pop(heap):
    return -heapq.heappop(heap)

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    heap = []

    for i in range(n):
        push(heap, a[i])

    for i in range(m):
        tm = pop(heap)
        tm //= 2
        push(heap, tm)

    ans = 0
    for i in range(n):
        ans += heap[i]

    print(-ans)

if __name__ == "__main__":
    main()


