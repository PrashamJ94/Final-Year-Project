import sys
from typing import List, Tuple

def main() -> None:
    N, P, S = input().split()
    N, P = int(N), int(P)
    answer = check_sub_numbers(N, P, S)
    print(answer)

def check_sub_numbers(N: int, P: int, S: str) -> int:
    if P in [2, 5]:
        return check_two_or_five(N, P, S)
    else:
        return check_not_two_nor_five(N, P, S)

def check_two_or_five(N: int, P: int, S: str) -> int:
    answer = 0
    for i in range(N):
        n = int(S[i])
        if n % P == 0:
            answer += i + 1
    return answer

def check_not_two_nor_five(N: int, P: int, S: str) -> int:
    multiplier = 1
    answer = 0
    remainder_lookup = [0] * P
    prev_remainder = -1
    for i in range(N - 1, -1, -1):
        digit = int(S[i])
        if prev_remainder == -1:
            remainder = digit % P
        else:
            remainder = (((multiplier * digit) % P) + prev_remainder) % P
        if remainder == 0:
            answer += 1
        count = remainder_lookup[remainder]
        answer += count
        count += 1
        remainder_lookup[remainder] = count
        prev_remainder = remainder
        multiplier = (multiplier * 10) % P
    return answer

if __name__ == "__main__":
    main()


