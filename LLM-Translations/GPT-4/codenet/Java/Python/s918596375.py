import sys
from io import StringIO
import math


def main():
    input_string = sys.stdin.read()
    input_list = input_string.strip().split('\n')
    solve(input_list)


def solve(input_list):
    s = input_list[0]

    a = ["a", "e", "i", "o", "u"]

    for str in a:
        if str.lower() == s.lower():
            print("vowel")
            return

    print("consonant")


def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(b, a % b)


def lcm(a, b):
    return (a * b) // gcd(a, b)


if __name__ == "__main__":
    main()


