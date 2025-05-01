import sys

def main():
    n = int(input().strip())
    result = 0
    h = []
    g = []
    for _ in range(n):
        home, guest = map(int, input().strip().split())
        h.append(home)
        g.append(guest)
    for i in range(n):
        for j in range(n):
            if h[i] == g[j]:
                result += 1
    print(result)

if __name__ == "__main__":
    main()


