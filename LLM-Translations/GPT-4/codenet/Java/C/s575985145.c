#include <stdio.h>

int main() {
    int size, id, cols, i, j;
    scanf("%d", &size);
    int graph[size][size];

    for (i = 0; i < size; i++) {
        scanf("%d %d", &id, &cols);
        int row[size];
        for (j = 0; j < size; j++)
            row[j] = 0;
        for (j = 0; j < cols; j++) {
            int temp;
            scanf("%d", &temp);
            row[temp - 1] = 1;
        }
        for (j = 0; j < size; j++)
            graph[id - 1][j] = row[j];
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d", graph[i][j]);
            if (j < size - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

// 
