
from collections import deque

def rev(s):
    return s[::-1]

def main():
    S = input().strip()
    Q = int(input().strip())

    ops = []

    for _ in range(Q):
        query = input().split()
        if query[0] == '1':
            ops.append({"rev": True})
        else:
            ops.append({"rev": False, "front": query[1] == '1', "c": query[2]})

    sum = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i]["rev"]:
            sum[i - 1] = sum[i] + 1
        else:
            sum[i - 1] = sum[i]

    if sum[0] % 2 == 1:
        S = rev(S)

    deq = deque()

    for i in range(Q):
        if not ops[i]["rev"]:
            if ops[i]["front"]:
                if sum[i] % 2 == 1:
                    deq.append(ops[i]["c"])
                else:
                    deq.appendleft(ops[i]["c"])
            else:
                if sum[i] % 2 == 1:
                    deq.appendleft(ops[i]["c"])
                else:
                    deq.append(ops[i]["c"])

    front = ''.join(deq)
    result = front + S

    print(result)

if __name__ == "__main__":
    main()


