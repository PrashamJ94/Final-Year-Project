
#include <stdio.h>

int main() {
    int N, count_best = 0, count_tmp = 0;
    scanf("%d", &N);
    
    int H[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        if (H[i] >= H[i + 1]) {
            count_tmp++;
        } else {
            if (count_tmp > count_best) {
                count_best = count_tmp;
            }
            count_tmp = 0;
        }
    }

    if (count_tmp > count_best) {
        count_best = count_tmp;
    }

    printf("%d\n", count_best);
    return 0;
}

