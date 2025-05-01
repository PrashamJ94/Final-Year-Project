#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, arr[] = {111, 222, 333, 444, 555, 666, 777, 888, 999};
    scanf("%d", &N);

    int *ans_idx = (int*) bsearch(&N, arr, 9, sizeof(int), cmpfunc);
    if (ans_idx == NULL) {
        printf("%d\n", arr[0]);
    } else {
        printf("%d\n", *ans_idx);
    }

    return 0;
}
// 
