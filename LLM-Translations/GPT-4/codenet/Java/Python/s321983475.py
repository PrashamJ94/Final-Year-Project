import sys

def main():
    w, a, b = map(int, sys.stdin.readline().split())
    
    answer = max(a, b) - min(a, b) - w
    if answer < 0:
        print(0)
    else:
        print(answer)

if __name__ == "__main__":
    main()


