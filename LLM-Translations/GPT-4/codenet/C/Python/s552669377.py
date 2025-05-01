def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    
    min_val = min(numbers)
    max_val = max(numbers)
    sum_val = sum(numbers)
    
    print(min_val, max_val, sum_val)

if __name__ == "__main__":
    main()


