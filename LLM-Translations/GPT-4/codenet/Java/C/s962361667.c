#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int w, n;
    scanf("%d %d", &w, &n);
    int values[w];
    for (int i = 0; i < w; i++) {
        values[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int x = 0;
        char str[10];
        scanf("%s", str);
        char *token;
        token = strtok(str, ",");
        int a = atoi(token) - 1;
        token = strtok(NULL, ",");
        int b = atoi(token) - 1;
        x = values[a];
        values[a] = values[b];
        values[b] = x;
    }
    for (int i = 0; i < w; i++) {
        printf("%d\n", values[i]);
    }
    return 0;
}
// 
