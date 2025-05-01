
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ds[1000];
    int dn[1000];
    int len, sum = 0;

    fgets(ds, sizeof(ds), stdin);
    fgets(ds, sizeof(ds), stdin);

    char *token = strtok(ds, " ");
    for (len = 0; token != NULL; len++) {
        dn[len] = atoi(token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            sum += dn[i] * dn[j];
        }
    }

    printf("%d\n", sum);

    return 0;
}

// 
