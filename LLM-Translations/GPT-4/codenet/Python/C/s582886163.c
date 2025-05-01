
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int capacity_list[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &capacity_list[i]);
    }

    qsort(capacity_list, 5, sizeof(int), compare);

    int bottle_neck = capacity_list[0];
    printf("%d\n", 4 + (int)((N + bottle_neck - 1) / bottle_neck));

    return 0;
}


