
from collections import Counter

def main():
    W = input().strip()
    
    count = Counter(W)
    for value in count.values():
        if value % 2 != 0:
            print("No")
            return

    print("Yes")

if __name__ == "__main__":
    main()


