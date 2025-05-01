Here is the Python equivalent of your provided Java code:


from collections import defaultdict

def main():
    n = int(input().strip())
    vals = list(map(int, input().strip().split()))
    frequency_map = defaultdict(int)
    for val in vals:
        frequency_map[val] += 1
    max_val = max(frequency_map.values())
    print(max_val, len(frequency_map))

if __name__ == "__main__":
    main()


