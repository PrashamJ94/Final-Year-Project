import sys

def main():
    n, a, b = map(int, sys.stdin.readline().split())
    sa = abs(a - b)

    if sa % 2 == 0:
        ans = sa // 2
    else:
        AAA = min(n - a, a - 1)
        BBB = min(n - b, b - 1)

        ans = min(AAA, BBB)  # One of them reaches the edge.

        # Decrease the difference by 1 => The difference becomes even
        sa -= 1
        ans += 1

        # The difference is even
        ans += sa // 2

    print(ans)


if __name__ == "__main__":
    main()


