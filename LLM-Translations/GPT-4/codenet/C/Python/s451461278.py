def partition(C, A, p, r):
    x = C[r]
    y = A[r]
    i = p - 1

    for j in range(p, r):
        if A[j] <= y:
            i = i + 1
            A[i], A[j] = A[j], A[i]
            C[i], C[j] = C[j], C[i]

    A[i+1], A[r] = A[r], A[i+1]
    C[i+1], C[r] = C[r], C[i+1]

    return i + 1

def quicksort(C, A, p, r):
    if p < r:
        q = partition(C, A, p, r)
        quicksort(C, A, p, q-1)
        quicksort(C, A, q+1, r)

def merge(MC, MN, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    LN = MN[left:left + n1] + [1000000000]
    RN = MN[mid + 1:mid + n1 + 1] + [1000000000]
    LC = MC[left:left + n1] + ['']
    RC = MC[mid + 1:mid + n1 + 1] + ['']

    i = j = 0

    for k in range(left, right + 1):
        if LN[i] <= RN[j]:
            MN[k] = LN[i]
            MC[k] = LC[i]
            i += 1
        else:
            MN[k] = RN[j]
            MC[k] = RC[j]
            j += 1

def merge_sort(MC, MN, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(MC, MN, left, mid)
        merge_sort(MC, MN, mid + 1, right)
        merge(MC, MN, left, mid, right)

def main():
    n = int(input())
    data = [input().split() for _ in range(n)]
    C, A = zip(*data)
    A = list(map(int, A))

    MC, MN = list(C), list(A)
    merge_sort(MC, MN, 0, n - 1)

    quicksort(C, A, 0, n - 1)

    if MC == C and MN == A:
        print("Stable")
    else:
        print("Not stable")

    for i in range(n):
        print(C[i], A[i])

if __name__ == "__main__":
    main()


