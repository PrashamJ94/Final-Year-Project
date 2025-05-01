#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *number, char *target, char *ans, char **list, int *index) {
    if (strlen(target) <= 1) {
        strcpy(list[*index], ans);
        strcat(list[*index], target);
        (*index)++;
    } else {
        for (int i = 0; i < strlen(target); i++) {
            char new_target[strlen(target)];
            strncpy(new_target, target, i);
            strcpy(new_target + i, target + i + 1);
            
            char new_ans[strlen(ans) + 2];
            strcpy(new_ans, ans);
            new_ans[strlen(ans)] = target[i];
            new_ans[strlen(ans) + 1] = '\0';
            
            permutation(number, new_target, new_ans, list, index);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char line[2][n + 1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);
            line[i][j] = num + '0';
        }
        line[i][n] = '\0';
    }

    char number[n + 1];
    for (int i = 1; i <= n; i++) {
        number[i - 1] = i + '0';
    }
    number[n] = '\0';

    char **listA = malloc(sizeof(char *) * 362880);
    for (int i = 0; i < 362880; i++) {
        listA[i] = malloc(sizeof(char) * (n + 1));
    }

    int index = 0;
    permutation(number, number, "", listA, &index);

    int sum = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < index; i++) {
            if (strcmp(listA[i], line[j]) == 0) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }

    printf("%d\n", abs(sum));

    for (int i = 0; i < 362880; i++) {
        free(listA[i]);
    }
    free(listA);

    return 0;
}
// //End of Code
