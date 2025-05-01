#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int candy[3];
    scanf("%d %d %d", &candy[0], &candy[1], &candy[2]);

    qsort(candy, 3, sizeof(int), compare);

    if (candy[0] + candy[1] == candy[2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// 
