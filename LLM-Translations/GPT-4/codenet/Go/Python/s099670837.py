def find_ans(i, j, sum_, a, n):
    if i == 1 and j == n - 1:
        return sum_ + a[i][j]
    if i == 0:
        sum1 = find_ans(i + 1, j, sum_ + a[i][j], a, n)
    else:
        sum1 = 0
    if j + 1 < n:
        sum2 = find_ans(i, j + 1, sum_ + a[i][j], a, n)
    else:
        sum2 = 0
    return max(sum1, sum2)

def main():
    n = int(input())
    a = []
    for _ in range(2):
        a.append(list(map(int, input().split())))

    ans = find_ans(0, 0, 0, a, n)
    print(ans)

if __name__ == "__main__":
    main()


