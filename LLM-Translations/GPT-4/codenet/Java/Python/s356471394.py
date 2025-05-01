import sys

def input():
    return sys.stdin.readline().strip()

def setWE(N, M, D, room):
    num = 0
    for i in range(N):
        for j in range(M - D + 1):
            canPut = True
            for k in range(D):
                if room[i][j + k] == '#':
                    canPut = False
                    break
            if canPut:
                num += 1
    return num

def setNS(N, M, D, room):
    num = 0
    for i in range(M):
        for j in range(N - D + 1):
            canPut = True
            for k in range(D):
                if room[j + k][i] == '#':
                    canPut = False
                    break
            if canPut:
                num += 1
    return num

def main():
    N, M, D = map(int, input().split())
    room = [input() for _ in range(N)]
    num = 0
    
    if M >= D:
        num += setWE(N, M, D, room)

    if N >= D:
        num += setNS(N, M, D, room)

    print(num)

if __name__ == "__main__":
    main()


