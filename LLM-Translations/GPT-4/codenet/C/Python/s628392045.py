def main():
    n = int(input())
    h = list(map(int, input().split()))
    max_h = max(h)
    flag = False
    
    for height in h:
        if max_h - height >= 2:
            flag = True
            break
    
    if flag:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()


