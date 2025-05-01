def main():
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    
    for i in range(n):
        l = i
        for j in range(i+1, n):
            if p[j] < p[l]:
                l = j
        if l != i:
            m = p[i]
            p[i] = p[l]
            p[l] = m
    
    o = sum(p[:k])
    print(o)

if __name__ == "__main__":
    main()


