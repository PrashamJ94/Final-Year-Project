
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solve() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int min = arr[0];

    for (int i = 0; i < N; i++) {
        if (arr[i] <= min) {
            sum++;
            min = arr[i];
        }
    }

    return sum;
}

int main() {
    printf("%d\n", solve());
    return 0;
}

// //End of Code
