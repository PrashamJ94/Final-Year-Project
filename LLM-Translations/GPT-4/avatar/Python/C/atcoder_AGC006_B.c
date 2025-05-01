#include <stdio.h>
#include <stdlib.h>

int calc(int *x, int len, int debug) {
    while(len > 1) {
        int *y = (int *) malloc(sizeof(int) * (len - 2));
        for(int i = 0; i < len - 2; i++) {
            int arr[3] = {x[i], x[i+1], x[i+2]};
            qsort(arr, 3, sizeof(int), compare);
            y[i] = arr[1];
        }
        free(x);
        x = y;
        len -= 2;
        if(debug){
            for(int i = 0; i < len; i++){
                printf("D %d ", x[i]);
            }
            printf("\n");
        }
    }
    return x[0];
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    if(X == 1 || X == N * 2 - 1) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
        int xs[2*N - 1];
        if(X == N * 2 - 2) {
            for(int i = 0; i < N - 1; i++)
                xs[i] = i + N;
            for(int i = N - 1; i < 2*N - 1; i++)
                xs[i] = i - N + 2;
        }
        else {
            int ys[2*N - 1];
            for(int i = 0; i < X - 1; i++)
                ys[i] = i + 1;
            for(int i = X - 1; i < 2*N - 2; i++)
                ys[i] = i + X + 3;
            for(int i = 0; i < N - 3; i++)
                xs[i] = ys[i];
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for(int i = N + 1; i < 2*N - 1; i++)
                xs[i] = ys[i - 3];
        }
        for(int i = 0; i < 2*N - 1; i++)
            printf("%d\n", xs[i]);
    }
    return 0;
}
/* End of Code */
