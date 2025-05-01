def search(A, n, key):
    i = 0
    A.append(key)
    while A[i] != key:
        i += 1
    A.pop()
    return i != n

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    sum = 0
    for _ in range(q):
        key = int(input())
        if search(A, n, key):
            sum += 1
    print(sum)

if __name__ == "__main__":
    main()


