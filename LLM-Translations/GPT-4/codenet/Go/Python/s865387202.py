import sys
from typing import List, Tuple

def main():
    n, m = map(int, input().split())
    h = {}
    city_list = []
    for i in range(m):
        x, y = map(int, input().split())
        if x not in h:
            h[x] = [(y, i)]
        else:
            h[x].append((y, i))

    results = [""] * m

    for key in h:
        h[key].sort()
        for idx, (year, position) in enumerate(h[key]):
            results[position] = f"{key:06}{idx+1:06}"

    print("\n".join(results))

if __name__ == "__main__":
    main()


