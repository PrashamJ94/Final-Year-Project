
#include <stdio.h>
#include <limits.h>

long min = LONG_MAX;

void util(long arr[], int arr_size, char ops[], int idx) {
    if (idx == 3) {
        if (arr[0] < min) min = arr[0];
        return;
    }
    for (int i = 0; i < arr_size; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            long a[arr_size - 1];
            int a_idx = 0;
            for (int k = 0; k < arr_size; k++) {
                if (k != j && k != i) {
                    a[a_idx++] = arr[k];
                }
            }
            long res;
            if (idx < 3 && ops[idx] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }
            a[a_idx] = res;
            util(a, arr_size - 1, ops, idx + 1);
        }
    }
}

int main() {
    long arr[4];
    char ops[3];
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i]);
    }
    util(arr, 4, ops, 0);
    printf("%ld\n", min);
    return 0;
}

/* //End of Code */
