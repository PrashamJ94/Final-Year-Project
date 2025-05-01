import sys

def main():
    n = int(input().strip())
    heights = list(map(int, input().strip().split()))
    minN = heights[0] - 1
    for h in heights[1:]:
        if minN == h:
            minN = h
        elif minN == h - 1:
            minN = h - 1
        elif minN < h - 1:
            minN = h - 1
        elif minN > h:
            print("No")
            return
    print("Yes")

if __name__ == "__main__":
    main()


