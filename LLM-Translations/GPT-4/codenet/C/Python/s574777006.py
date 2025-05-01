def main():
    n = int(input())
    x = list(map(int, input().split()))
    
    q = int(input())
    y = [int(input()) for _ in range(q)]
    
    sum = 0
    
    for i in range(q):
        for j in range(n):
            if y[i] == x[j]:
                sum += 1
                break
                
    print(sum)

if __name__ == "__main__":
    main()


