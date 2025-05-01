#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pair {
    int x;
    int y;
} Pair;

int compare(const void *a, const void *b) {
    Pair p1 = *(Pair *)a;
    Pair p2 = *(Pair *)b;
    int min1 = p1.x < p1.y ? p1.x : p1.y;
    int min2 = p2.x < p2.y ? p2.x : p2.y;

    if (min1 != min2) return min2 - min1;
    if (p1.x == p2.x) return p1.y - p2.y;
    return p1.x - p2.x;
}

int main() {
    int n;
    scanf("%d", &n);
    Pair arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, n, sizeof(Pair), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}

// 
