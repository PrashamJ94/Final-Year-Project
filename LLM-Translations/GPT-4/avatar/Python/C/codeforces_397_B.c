#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int queries[t][3];
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }
    char* res[t];
    for (int i = 0; i < t; i++) {
        int k = queries[i][0] / queries[i][1];
        if (k * queries[i][2] >= queries[i][0]) {
            res[i] = "Yes";
        } else {
            res[i] = "No";
        }
    }
    for (int i = 0; i < t; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
} // End of Code
