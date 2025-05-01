#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    int m = 0;
    for(int i=1;i<n;i++)
        if(abs(a[m]) < abs(a[i]))
            m = i;

    int rSize = 0;
    char** r = malloc(n * 2 * sizeof(char *));
    for(int i=0;i<n;i++) {
        if((a[m] >= 0) ^ (a[i] >= 0)) {
            r[rSize] = malloc(20 * sizeof(char));
            sprintf(r[rSize++], "%d %d", m + 1, i + 1);
        }
    }

    if(a[m] >= 0) {
        for(int i=1;i<n;i++) {
            r[rSize] = malloc(20 * sizeof(char));
            sprintf(r[rSize++], "%d %d", i, i + 1);
        }
    } else {
        for(int i=n;i>1;i--) {
            r[rSize] = malloc(20 * sizeof(char));
            sprintf(r[rSize++], "%d %d", i, i - 1);
        }
    }

    printf("%d\n", rSize);
    for(int i=0;i<rSize;i++) {
        printf("%s\n", r[i]);
        free(r[i]);
    }
    free(r);

    return 0;
}

/* //End of Code */
