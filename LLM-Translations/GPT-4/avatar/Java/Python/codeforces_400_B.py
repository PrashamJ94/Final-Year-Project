import sys

def main():
    n, m = map(int, input().split())
    arrs = []
    for _ in range(n):
        arrs.append(input().strip())

    length = [0] * n
    index = 0
    returnDex = 0
    for tmp in arrs:
        dexG = tmp.index("G")
        dexS = tmp.index("S")
        if dexG > dexS:
            returnDex = -1
        length[index] = dexS - dexG
        index += 1

    unique_lengths = set(length)
    if returnDex == -1:
        print(returnDex)
    else:
        print(len(unique_lengths))

if __name__ == "__main__":
    main()


