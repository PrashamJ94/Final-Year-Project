import sys
from typing import List, Tuple

def from_input_string(input_string: str) -> Tuple:
    data = input_string.strip().split('\n')
    n = int(data[0])
    s = data[1]
    return n, s

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_input_string(inputs: Tuple) -> str:
    n, s = inputs
    return str(n) + '\n' + s + '\n'

def to_output_string(output: int) -> str:
    return str(output) + '\n'

def count_combinations(n: int, s: str) -> int:
    if n < 4:
        return 0

    nr, nb, ng = 0, 0, 0
    for c in s:
        if c == 'R':
            nr += 1
        elif c == 'B':
            nb += 1
        elif c == 'G':
            ng += 1

    same = 0
    for a in range(1, n):
        i, j, k = 0, 1 * a, 2 * a
        if k >= n:
            break
        while k < n:
            if s[i] != s[j] and s[i] != s[k] and s[j] != s[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng
    return tot - same

if __name__ == "__main__":
    n, s = from_input_string(sys.stdin.read())
    result = count_combinations(n, s)
    sys.stdout.write(to_output_string(result))


