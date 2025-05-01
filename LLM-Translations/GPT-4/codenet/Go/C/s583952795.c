
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Pair {
    void *p1, *p2;
} Pair;

char* ten_to_n(int number, int n) {
    char* s = (char*)malloc(20 * sizeof(char));
    memset(s, 0, 20);
    int tmp = number;

    while (1) {
        char str[2] = {0};
        sprintf(str, "%d", tmp % n);
        strcat(s, str);
        if (tmp < n) {
            break;
        }
        tmp /= n;
    }
    return s;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char* s = ten_to_n(N, K);
    printf("%lu\n", strlen(s));
    free(s);
}

// 


