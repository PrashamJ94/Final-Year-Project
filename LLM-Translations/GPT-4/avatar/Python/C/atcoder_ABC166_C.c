#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *p = malloc((n+1) * sizeof(int));
    for(int i=1; i<=n; i++) {
        p[i] = i;
    }

    int *h = malloc((n+1) * sizeof(int));
    for(int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }

    int **path = malloc((n+1) * sizeof(int*));
    for(int i=1; i<=n; i++) {
        path[i] = malloc(n * sizeof(int));
    }

    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][b] = 1;
        path[b][a] = 1;
    }

    int c = 0;
    for(int i=1; i<=n; i++) {
        int f = 0;
        for(int j=1; j<=n; j++) {
            if(path[i][j] == 1 && h[i] <= h[j]) {
                f = 1;
                break;
            }
        }

        if(f == 0) {
            c++;
        }
    }

    printf("%d\n", c);

    return 0;
} // End of Code.
