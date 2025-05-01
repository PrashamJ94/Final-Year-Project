def solve():
    n = int(input())
    as = list(map(int, input().split()))

    xs = [a - i + 1 for i, a in enumerate(as)]
    xs.sort()

    b = xs[n // 2]
    ans = sum(abs(x - b) for x in xs)
    print(ans)

def abs(n):
    return -n if n < 0 else n

# -----------------------------------------

def main():
    solve()

if __name__ == "__main__":
    main()


