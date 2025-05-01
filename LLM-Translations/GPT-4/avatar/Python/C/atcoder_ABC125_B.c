#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int V[N], C[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    for(i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }
    int list[N+1];
    list[0] = 0;
    int ans = 0;
    int X = 0, Y = 0;
    for(i = 0; i < N; i++) {
        if(V[i] - C[i] > 0){
            X = V[i];
            Y = C[i];
            list[i+1] = X - Y;
        }
        else{
            list[i+1] = 0;
        }
    }
    for(i = 0; i < N+1; i++) {
        ans += list[i];
    }
    printf("%d", ans);

    return 0;
}

// End of Code
