import sys

def main():
    VP, VD, T, F, C = map(int, input().split())
    
    if VD <= VP:
        print("0")
        return
    
    answer = 0
    start = T
    while True:
        x = start * VP / (VD - VP)
        if (start + x) * VP >= C:
            break
        
        start += 2 * x + F
        answer += 1
    
    print(answer)

if __name__ == "__main__":
    main()


