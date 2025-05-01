import bisect
import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    as_ = list(map(int, input().strip().split()))

    xs = [as_[0]]
    for a in as_[1:]:
        idx = bisect.bisect_left(xs, a)
        if idx == len(xs):
            xs.append(a)
        else:
            xs[idx] = a

    print(len(xs))

if __name__ == "__main__":
    main()


