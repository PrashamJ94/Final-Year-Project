
def main():
    x = [0] * 10000
    i = 0
    x[i] = int(input())
    
    while x[i] != 0:
        i += 1
        x[i] = int(input())
    
    for j in range(i):
        print(f"Case {j+1}: {x[j]}")
        
if __name__ == "__main__":
    main()


