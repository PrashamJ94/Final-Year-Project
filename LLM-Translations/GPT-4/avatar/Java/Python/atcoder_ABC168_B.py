
import sys

def main():
    K = int(input().strip())
    S = input().strip()
    
    if len(S) <= K:
        print(S)
    else:
        print(S[:K] + "...")

if __name__ == "__main__":
    main()


