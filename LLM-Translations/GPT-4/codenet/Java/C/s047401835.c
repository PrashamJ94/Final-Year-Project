#include <stdio.h>
#include <stdbool.h>

int main() {
    int N, i, count = 0;
    bool all_even;

    scanf("%d", &N);

    int numbers[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    do {
        all_even = true;
        for (i = 0; i < N; i++) {
            if (numbers[i] % 2 != 0) {
                all_even = false;
                break;
            }
            numbers[i] = numbers[i] / 2;
        }
        if (all_even) count++;
    } while (all_even);

    printf("%d\n", count);

    return 0;
}
/*  */
