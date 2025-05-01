import sys

def main():
    w, n = map(int, input().split())
    values = [i+1 for i in range(w)]
    
    for i in range(n):
        x = 0
        str = input()
        ab = str.split(",")
        a = int(ab[0]) - 1
        b = int(ab[1]) - 1
        x = values[a]
        values[a] = values[b]
        values[b] = x
    
    for i in range(w):
        print(values[i])

if __name__ == "__main__":
    main()


