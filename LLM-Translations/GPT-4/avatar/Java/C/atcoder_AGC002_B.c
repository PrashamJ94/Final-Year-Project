#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num;
    bool red;
} Box;

void moveTo(Box *src, Box *dest) {
    if (src->num == 0) {
        return;
    } else if (src->num == 1) {
        src->num = 0;
        dest->num++;
        if (src->red) {
            dest->red = true;
        }
        src->red = false;
    } else {
        src->num--;
        dest->num++;
        if (src->red) {
            dest->red = true;
        }
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    Box B[N];
    B[0] = (Box){1, true};
    for (int i = 1; i < N; i++) {
        B[i] = (Box){1, false};
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        moveTo(&B[x], &B[y]);
    }

    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++;
        }
    }

    printf("%d\n", counter);
    return 0;
}

// //End of Code.
