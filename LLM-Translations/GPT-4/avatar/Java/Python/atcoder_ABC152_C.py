
from queue import PriorityQueue

def atcoder_ABC152_C():
    N = int(input())
    arr = [int(x) for x in input().split()]
    sum = 0
    q = PriorityQueue()

    for i in range(len(arr)):
        q.put(arr[i])
        if arr[i] <= q.queue[0]:
            sum += 1

    return sum

if __name__ == "__main__":
    print(atcoder_ABC152_C())


