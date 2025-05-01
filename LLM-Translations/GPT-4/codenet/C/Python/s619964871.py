def sort(a, left, middle, right):
    unko = 1e12
    l_arr = a[left:middle] + [unko]
    r_arr = a[middle:right] + [unko]
    cnt = 0
    l, r = 0, 0
    for i in range(right - left):
        if l_arr[l] <= r_arr[r]:
            a[left + i] = l_arr[l]
            l += 1
        else:
            a[left + i] = r_arr[r]
            r += 1
            cnt += middle - left - l
    return cnt


def merge(a, left, right):
    if left + 1 < right:
        middle = (left + right) // 2
        x1 = merge(a, left, middle)
        x2 = merge(a, middle, right)
        x3 = sort(a, left, middle, right)
        return x1 + x2 + x3
    else:
        return 0


def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(merge(a, 0, n))


if __name__ == "__main__":
    main()


