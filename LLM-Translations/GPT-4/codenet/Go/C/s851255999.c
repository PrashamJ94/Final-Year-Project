
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time, limit;
} work;

int compare(const void *a, const void *b) {
    work *workA = (work *)a;
    work *workB = (work *)b;
    return workA->limit - workB->limit;
}

int main() {
    int n;
    scanf("%d", &n);
    work *ws = (work *)malloc(n * sizeof(work));
    for (int i = 0; i < n; i++) {
        int a, n;
        scanf("%d %d", &a, &n);
        ws[i].time = a;
        ws[i].limit = n;
    }
    qsort(ws, n, sizeof(work), compare);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            printf("No\n");
            free(ws);
            return 0;
        }
    }
    printf("Yes\n");
    free(ws);
    return 0;
}

// 
