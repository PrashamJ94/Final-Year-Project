#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int score[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }
    
    int mae = 0;
    int usiro = K;
    for (int i = 0; i < N-K; i++) {
        if (score[mae] < score[usiro]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        mae += 1;
        usiro += 1;
    }
    
    return 0;
}


