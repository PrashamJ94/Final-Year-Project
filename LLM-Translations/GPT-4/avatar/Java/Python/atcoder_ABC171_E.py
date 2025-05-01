import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    r = 0
    
    for i in range(n):
        r ^= a[i]
        
    for i in range(n):
        if i != 0:
            sys.stdout.write(" ")
        sys.stdout.write(str(r ^ a[i]))

if __name__ == "__main__":
    main()


