import sys

def main():
    n, q = map(int, sys.stdin.readline().split())
    c = sys.stdin.readline().strip()
    range_list = [tuple(map(int, sys.stdin.readline().split())) for _ in range(q)]
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)
    
    for i in range(2, n + 1):
        if c[i - 2] == 'A' and c[i - 1] == 'C':
            frag[i] += 1
        rui[i] = rui[i - 1] + frag[i]
    
    for i in range(q):
        left, right = range_list[i]
        print(rui[right] - rui[left])

if __name__ == "__main__":
    main()


