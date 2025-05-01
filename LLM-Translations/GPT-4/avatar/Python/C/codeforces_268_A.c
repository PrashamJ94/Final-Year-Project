#include <stdio.h>
#include <string.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    char q[n][20];

    for(int i = 0; i < n; i++) {
        scanf("%s", q[i]);
    }

    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            if(k == j) {
                continue;
            }
            else if(q[j][0] == q[k][strlen(q[k]) - 1]) {
                count++;
            }
            else {
                continue;
            }
        }
    }

    printf("%d", count);

    return 0;
} 
// End of Code
