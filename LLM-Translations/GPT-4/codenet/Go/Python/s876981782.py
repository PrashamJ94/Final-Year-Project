
import sys
from typing import List

def main():
    N = int(input().strip())
    values = list(map(float, input().strip().split()))
    values.sort()

    generated = 0
    for i in range(N - 1):
        generated = (values[i] + values[i + 1]) / 2
        values[i + 1] = generated

    print(generated)

if __name__ == "__main__":
    main()


