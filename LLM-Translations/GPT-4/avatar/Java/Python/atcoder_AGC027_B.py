import sys
from typing import List, Tuple


def from_input_string(input_string: str) -> Tuple[int, int, List[int]]:
    data = input_string.strip().split('\n')
    n, x = map(int, data[0].split())
    x_values = list(map(int, data[1].split()))
    return n, x, x_values


def from_output_string(output_string: str) -> int:
    return int(output_string.strip())


def to_input_string(inputs: Tuple[int, int, List[int]]) -> str:
    n, x = inputs[0], inputs[1]
    x_values = " ".join(str(i) for i in inputs[2])
    return f"{n} {x}\n{x_values}\n"


def to_output_string(output: int) -> str:
    return str(output)


def solve(n: int, x: int, x_values: List[int]) -> int:
    xsum = [0] * (n + 1)
    for i in range(n):
        xsum[i + 1] = xsum[i] + x_values[i]

    ans = x * n + 5 * xsum[n]

    for i in range(1, n):
        cost = x * i + 5 * (xsum[n] - xsum[n - i])

        j, k = 5, n - i
        while k >= 0:
            if cost > ans:
                break
            cost += j * (xsum[k] - xsum[max(k - i, 0)])
            j += 2
            k -= i

        ans = min(ans, cost)

    return ans + n * x


