#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str2List(char *str, int *ret) {
    char *token = strtok(str, " ");
    int key = 0;
    while (token != NULL) {
        ret[key] = atoi(token);
        token = strtok(NULL, " ");
        key++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int vList[n], cList[n];
    char vStr[100], cStr[100];
    fgets(vStr, sizeof(vStr), stdin);
    str2List(vStr, vList);
    
    fgets(cStr, sizeof(cStr), stdin);
    str2List(cStr, cList);

    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    printf("%d\n", max);

    return 0;
}

/* //End of Code */
