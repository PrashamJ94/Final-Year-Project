#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int *l = (int*) malloc(n*sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    int b = l[0];
    int s = 0;

    for (i = 0; i < n; i++) {
        if (l[i] > b) {
            b = l[i];
        }
        s += l[i];
    }

    if (b < s - b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(l);
    return 0;
}
// 
