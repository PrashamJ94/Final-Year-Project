def main():
    n, k = map(int, input().split())

    if k <= (n + n % 2) // 2:
        print("YES")
    else:
        print("NO")
        
if __name__ == "__main__":
    main()


