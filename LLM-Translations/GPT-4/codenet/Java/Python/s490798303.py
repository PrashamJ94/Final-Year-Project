import sys
from collections import defaultdict

def main():
    n, k = map(int, input().split())

    person_map = defaultdict(list)

    for i in range(k):
        d, *persons = map(int, input().split())
        for person in persons:
            person_map[person].append(d)

    count = 0
    for i in range(1, n + 1):
        if i not in person_map:
            count += 1

    print(count)

if __name__ == "__main__":
    main()


