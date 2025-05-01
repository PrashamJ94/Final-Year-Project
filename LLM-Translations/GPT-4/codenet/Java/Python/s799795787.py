import sys
from collections import Counter

def main():
    n = int(input().strip())
    array = []
    for _ in range(n):
        array.append(input().strip())
    
    array.sort()
    
    unique_elements = len(Counter(array).keys())
    
    print(unique_elements)

main()

