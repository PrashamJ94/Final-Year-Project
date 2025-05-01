
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    scanf("%d", &n);
    Item *input_array = malloc(n * sizeof(Item));
    int *outdated = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S && input_array[i].R < input_array[j].R && input_array[i].H < input_array[j].H) {
                outdated[i] = 1;
            }
        }
    }
    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++) {
        if (!outdated[i] && input_array[i].C < minimum_cost) {
            minimum_cost = input_array[i].C;
            input_number = i + 1;
        }
    }
    printf("%d\n", input_number);
    free(input_array);
    free(outdated);
    return 0;
} /* End of Code */
