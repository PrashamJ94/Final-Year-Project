#include <stdio.h>
#include <stdlib.h>

int main() {
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);

    int* x = malloc(n * sizeof(int));
    int* y = malloc(n * sizeof(int));
    int* a = malloc(n * sizeof(int));

    int xmax = w, xmin = 0;
    int ymax = h, ymin = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &a[i]);

        switch (a[i]) {
            case 1:
                xmin = (xmin > x[i]) ? xmin : x[i];
                break;
            case 2:
                xmax = (xmax < x[i]) ? xmax : x[i];
                break;
            case 3:
                ymin = (ymin > y[i]) ? ymin : y[i];
                break;
            case 4:
                ymax = (ymax < y[i]) ? ymax : y[i];
                break;
        }
    }

    w = (xmax - xmin > 0) ? xmax - xmin : 0;
    h = (ymax - ymin > 0) ? ymax - ymin : 0;

    printf("%d\n", w * h);

    free(x);
    free(y);
    free(a);

    return 0;
}

//
