#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int64_t *)a - *(int64_t *)b);
}

int main() {
    int64_t A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// 
