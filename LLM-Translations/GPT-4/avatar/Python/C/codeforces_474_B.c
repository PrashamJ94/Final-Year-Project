#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, r = 1, index;
    int L[1000], k[1000], j[1000];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
        for(int l = 0; l < k[i]; l++) {
            L[l] = r;
        }
        r++;
    }

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &j[i]);
        index = j[i] - 1;
        printf("%d\n", L[index]);
    }

    return 0;
} 
// End of Code
