
def counting_sort(A, B, k, len_A):
    C = [0] * (k + 1)
    for j in range(len_A):
        C[A[j]] += 1
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    for j in range(len_A - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1

def main():
    A = [int(x) for x in input().split()]
    len_A = len(A)
    B = [0] * len_A
    k = max(A)
    counting_sort(A, B, k, len_A)
    print(' '.join(map(str, B)))

if __name__ == "__main__":
    main()


