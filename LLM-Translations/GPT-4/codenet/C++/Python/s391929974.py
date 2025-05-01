
from sys import stdin

def main():
    while True:
        n = int(input())
        if not n:
            break

        sq = [(i*i) % n for i in range(1, n)]
        com = []

        for i in range(1, n):
            if sq[i] not in com:
                com.append(sq[i])

        fr = [0] * ((n - 1) // 2 + 1)

        for i in range(len(com)):
            for j in range(len(com)):
                if i != j:
                    tmp = com[i] - com[j]
                    if tmp < 0:
                        tmp += n
                    if tmp > (n - 1) // 2:
                        tmp = n - tmp
                    fr[tmp] += 1

        for i in range(1, (n - 1) // 2 + 1):
            print(fr[i])

if __name__ == "__main__":
    main()


