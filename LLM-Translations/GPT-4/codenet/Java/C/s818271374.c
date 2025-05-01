#include <stdio.h>

int main() {
    int N, a, count1 = 0, count2 = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a % 4 == 0) {
            count1++;
        } else if (a % 2 == 0 && (a / 2) % 2 == 1) {
            count2++;
        }
    }

    if (count1 >= N / 2) {
        printf("Yes\n");
    } else if (((N / 2 - count1) * 2 + N % 2) == count2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

//
