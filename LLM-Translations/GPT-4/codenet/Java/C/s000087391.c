#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *result;
    int resultSize = 0;
    char line[1024];
    int n = -1;
    while(1) {
        fgets(line, 1024, stdin);
        n = atoi(line);
        if(n == 0) {
            break;
        }
        result = (int *)realloc(result, (resultSize + 1) * sizeof(int));
        fgets(line, 1024, stdin);
        char *token = strtok(line, " ");
        int *input = (int *)malloc(n * sizeof(int));
        int sum = 0;
        for(int i = 0; i < n; i++) {
            input[i] = atoi(token);
            sum += input[i];
            token = strtok(NULL, " ");
        }
        double avg = (double)sum / (double)n;
        int num = 0;
        for(int i = 0; i < n; i++) {
            if(input[i] <= avg) {
                num++;
            }
        }
        result[resultSize++] = num;
        free(input);
    }
    for(int i = 0; i < resultSize; i++) {
        if(result[i] == -1) {
            printf("NONE\n");
        } else {
            printf("%d\n", result[i]);
        }
    }
    free(result);
    return 0;
}
