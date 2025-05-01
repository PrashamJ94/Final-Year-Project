import sys
from io import StringIO

def get_next_int(input_data):
    value = int(input_data.pop(0))
    return value

def main(input_str):
    input_data = input_str.strip().split()
    n = get_next_int(input_data)
    mm = [0] * (n + 1)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        mm[i] = get_next_int(input_data)
        mm[i + 1] = get_next_int(input_data)

    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    return dp[1][n]

input_str = sys.stdin.read()
result = main(input_str)
print(result)


