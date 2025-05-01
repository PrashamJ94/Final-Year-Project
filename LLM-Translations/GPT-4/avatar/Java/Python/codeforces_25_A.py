
def main():
    n = int(input())
    array = [0] + [int(x) for x in input().split()]
    odd, even, odd_ind, even_ind = 0, 0, 0, 0
    
    for i in range(1, n+1):
        if array[i] % 2 == 0:
            even += 1
            even_ind = i
        else:
            odd += 1
            odd_ind = i
            
    if odd > even:
        print(even_ind)
    else:
        print(odd_ind)

if __name__ == "__main__":
    main()


