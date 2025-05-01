#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int comparator(const void *p, const void *q) {
    return ( *(int*)p - *(int*)q );
}

int main() {
    int n, q, l, r, win;
    scanf("%d", &n);
    int answer[n];
    int left[n];
    for (int i = 0; i < n; i++) {
        left[i] = i;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &l, &r, &win);
        l--; r--; win--;
        for (int i = l; i <= r; i++) {
            answer[i] = win + 1;
            left[i] = -1;
        }
        answer[win] = 0;
        left[win] = win;
    }
    // Sort the array
    qsort((void*)left, n, sizeof(left[0]), comparator);
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}

// //End of Code
