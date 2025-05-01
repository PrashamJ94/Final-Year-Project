#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int array_length = 3 * n;
    int array[array_length];

    for (int i = 0; i < array_length; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, array_length, sizeof(int), compare_ints);

    int head = array_length - 2;
    long long res = 0;

    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }

    printf("%lld\n", res);

    return 0;
}
// //End of Code
