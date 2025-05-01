def reva(b):
    for i in range(len(b)//2):
        b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

def main():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    for _ in range(q):
        b, e = map(int, input().split())
        reva(a[b:e])
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()


