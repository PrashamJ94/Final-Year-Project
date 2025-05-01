
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int inf = INT_MAX;

void main() {
    char N[20];
    scanf("%s", N);
    int n = 0;

    for (int i = 0; i < strlen(N); i++) {
        n += N[i] - '0';
    }
    int m = atoi(N);
    if (m % n == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// 


