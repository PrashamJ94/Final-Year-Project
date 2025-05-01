#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    int N;
    long x;
    scanf("%d %ld", &N, &x);

    long sweet[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &sweet[i]);
    }

    qsort(sweet, N, sizeof(long), compare);

    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x - sweet[num] >= 0) {
            x = x - sweet[num];
            num++;
        } else {
            break;
        }
    }

    if ((num == N) && (x > 0)) {
        num -= 1;
    }

    printf("%d\n", num);
    return 0;
}

// //End of Code
