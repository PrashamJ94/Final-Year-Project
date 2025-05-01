#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int number, i;
    int *score;

    while (1) {
        scanf("%d", &number);
        if (number == 0)
            break;

        score = (int *)malloc(number * sizeof(int));
        for (i = 0; i < number; i++) {
            scanf("%d", &score[i]);
        }

        qsort(score, number, sizeof(int), compare);

        int sum = 0;
        for (i = 1; i < number - 1; i++) {
            sum = sum + score[i];
        }

        printf("%d\n", sum / (number - 2));

        free(score);
    }

    return 0;
}
/*  */
