import math

def main():
    N, M = map(int, input().split())
    ans = 0
    if N == 1 and M == 1:
        ans += 1
    elif 1 < N and 1 < M:
        ans += (N - 2) * (M - 2)
    else:
        ans += (N * M) - 2

    print(ans)

def max(*x):
    return max(x)

def min(*x):
    return min(x)

def pow(x, y):
    return x ** y

def abs(x):
    return abs(x)

def floor(x):
    return math.floor(x)

class SortBy:
    def __init__(self, a):
        self.a = a

    def __len__(self):
        return len(self.a)

    def swap(self, i, j):
        self.a[i], self.a[j] = self.a[j], self.a[i]

    def less(self, i, j):
        return abs(self.a[i]) < abs(self.a[j])

if __name__ == "__main__":
    main()


