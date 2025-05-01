import sys

def main():
    n = int(input().strip())
    str = input().strip()
    a = ""
    b = ""
    
    for i in range(n // 2):
        a += str[i]
        
    if str == (a + a):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


