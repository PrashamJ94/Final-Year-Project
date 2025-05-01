import sys

def main():
    Num = [0] * 11
    n = list(map(int, input().split()))
    
    for i in range(10):
        Num[i] = n[i]

    for a in range(9, -1, -1):
        for b in range(a):
            if Num[b] < Num[b+1]:
                Num[10] = Num[b]
                Num[b] = Num[b+1]
                Num[b+1] = Num[10]

    print(Num[0])
    print(Num[1])
    print(Num[2])

if __name__ == "__main__":
    main()


