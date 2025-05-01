#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stringToInt(char *s) {
    int n;
    sscanf(s, "%d", &n);
    return n;
}

int search(int len, int xs[], int as_j) {
    int i;
    for (i = 0; i < len; i++) {
        if (xs[i] < as_j) {
            return i;
        }
    }
    return len;
}

int main() {
    int mod = 1000000007;
    int n;
    scanf("%d", &n);
    int as[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }
    int xs[n];
    xs[0] = as[0];
    int len = 1;
    for (int j = 1; j < n; j++) {
        int idx = search(len, xs, as[j]);
        if (idx == len) {
            xs[len++] = as[j];
        } else {
            xs[idx] = as[j];
        }
    }
    printf("%d\n", len);
    return 0;
}
// 
