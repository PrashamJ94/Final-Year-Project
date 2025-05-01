def main():
    sum = 0
    n = int(input())
    numbers = list(map(int, input().split()))
    
    for i in range(n):
        m = numbers[i]
        sum += m
        if i == 0:
            min_num = m
            max_num = m
        
        if min_num > m:
            min_num = m
        if max_num < m:
            max_num = m
    
    print(min_num, max_num, sum)

if __name__ == "__main__":
    main()


