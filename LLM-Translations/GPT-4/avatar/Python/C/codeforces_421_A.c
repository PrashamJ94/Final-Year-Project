
#include <stdio.h>

int main() {
    int n, a, b, i, j;
    scanf("%d %d %d", &n, &a, &b);

    int lista[a], listb[b];

    for(i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }

    for(i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }

    for(i = 1; i <= n; i++) {
        int found = 0;
        for(j = 0; j < a; j++) {
            if(i == lista[j]) {
                printf("1 ");
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("2 ");
        }
    }

    return 0;
}
// End of Code


