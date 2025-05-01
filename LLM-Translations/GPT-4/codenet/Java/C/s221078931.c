#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int height;
    int width;
} IntegralRect;

int diagonal(IntegralRect *rect) {
    if (rect->height >= rect->width) {
        return INT_MAX;
    }
    return rect->height * rect->height + rect->width * rect->width;
}

int compare(const void *a, const void *b) {
    IntegralRect *rect1 = (IntegralRect *)a;
    IntegralRect *rect2 = (IntegralRect *)b;
    int d1 = diagonal(rect1);
    int d2 = diagonal(rect2);
    return d1 == d2 ? rect1->height - rect2->height : d1 - d2;
}

int main() {
    IntegralRect rects[40000];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j].height = i + 1;
            rects[i * 200 + j].width = j + 1;
        }
    }
    qsort(rects, 40000, sizeof(IntegralRect), compare);

    while (1) {
        int h, w;
        scanf("%d %d", &h, &w);

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect;
        tmpRect.height = h;
        tmpRect.width = w;
        int diag = diagonal(&tmpRect);

        for (int i = 0; i < 40000; i++) {
            if (compare(&rects[i], &tmpRect) > 0) {
                printf("%d %d\n", rects[i].height, rects[i].width);
                break;
            }
        }
    }

    return 0;
}
