import sys
from typing import List, Tuple

def main() -> None:
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    ans = "second"
    for i in range(n):
        if a[i] % 2 == 1:
            ans = "first"
            break
    print(ans)

if __name__ == "__main__":
    main()


