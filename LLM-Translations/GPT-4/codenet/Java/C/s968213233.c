#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a;
    int b;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pa = (Pair *)a;
    Pair *pb = (Pair *)b;
    return (pa->a < pb->a) - (pa->a > pb->a);
}

long long solve(int N, int *A) {
    qsort(A, N, sizeof(int), compare);

    long long res = 0;

    Pair *queue = malloc(N * sizeof(Pair));
    int qSize = 0;
    queue[qSize].a = A[N - 1];
    queue[qSize].b = A[N - 1];
    qSize++;

    for (int i = N - 2; i >= 0; i--) {
        int a = A[i];
        Pair place = queue[--qSize];
        res += (place.a < place.b) ? place.a : place.b;
        queue[qSize].a = place.a;
        queue[qSize].b = a;
        qSize++;
        queue[qSize].a = a;
        queue[qSize].b = place.b;
        qSize++;
    }
    free(queue);
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    long long res = solve(N, A);
    printf("%lld\n", res);

    free(A);
    return 0;
}
// 
