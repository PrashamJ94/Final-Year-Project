import sys

def find(a, b):
    calc = 0
    for x in range(len(a)):
        if a[x] != b[x]:
            calc += 1
    return calc

def main():
    S = input().strip()
    T = input().strip()
    min_value = sys.maxsize
    for i in range(0, len(S) - len(T) + 1):
        min_value = min(min_value, find(S[i:i+len(T)], T))
    if min_value != sys.maxsize:
        print(min_value)
    else:
        print(len(T))

if __name__ == "__main__":
    main()


