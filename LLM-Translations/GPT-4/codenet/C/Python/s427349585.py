def merge(a, n, l, m, r):
    L = a[l:m] + [{'s': '', 'v': 2000000000}]
    R = a[m:r] + [{'s': '', 'v': 2000000000}]
    i = j = 0
    for k in range(l, r):
        if L[i]['v'] <= R[j]['v']:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def merge_sort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, n, l, m)
        merge_sort(a, n, m, r)
        merge(a, n, l, m, r)

def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j]['v'] <= x['v']:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quick_sort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quick_sort(a, n, p, q - 1)
        quick_sort(a, n, q + 1, r)

def main():
    n = int(input())
    a = [0] * n
    b = [0] * n

    for i in range(n):
        s, v = input().split()
        v = int(v)
        a[i] = b[i] = {'s': s, 'v': v}

    merge_sort(a, n, 0, n)
    quick_sort(b, n, 0, n - 1)

    stable = 1
    for i in range(n):
        if a[i]['s'] != b[i]['s']:
            stable = 0

    if stable == 1:
        print("Stable")
    else:
        print("Not stable")

    for i in range(n):
        print(b[i]['s'], b[i]['v'])

main()


