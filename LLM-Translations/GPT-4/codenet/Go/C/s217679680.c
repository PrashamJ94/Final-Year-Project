#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *scanArrayInt(char *input);
int main() {
    char input[] = "5 20";
    int *arr = scanArrayInt(input);
    int a = arr[0], b = arr[1];
    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    printf("%d\n", tap);
    free(arr);
    return 0;
}

int *scanArrayInt(char *input) {
    int *ret = (int *)malloc(2 * sizeof(int));
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        ret[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return ret;
}
// 
